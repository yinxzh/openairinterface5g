/*
 * Licensed to the OpenAirInterface (OAI) Software Alliance under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The OpenAirInterface Software Alliance licenses this file to You under
 * the OAI Public License, Version 1.1  (the "License"); you may not use this file
 * except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.openairinterface.org/?page_id=698
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *-------------------------------------------------------------------------------
 * For more information about the OpenAirInterface (OAI) Software Alliance:
 *      contact@openairinterface.org
 */

/*! \file netlink_init.c
* \brief initiate the netlink socket for communication with nas dirver
* \author Navid Nikaein and Raymomd Knopp
* \date 2011
* \version 1.0
* \company Eurecom
* \email: navid.nikaein@eurecom.fr
*/

#include <sys/socket.h>
#include <linux/netlink.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include "platform_constants.h"
#ifdef UE_NAS_USE_TUN
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include "openairinterface5g_limits.h"
#endif

char nl_rx_buf[NL_MAX_PAYLOAD];

struct sockaddr_nl nas_src_addr, nas_dest_addr;
struct nlmsghdr *nas_nlh_tx = NULL;
struct nlmsghdr *nas_nlh_rx = NULL;
struct iovec nas_iov_tx;
struct iovec nas_iov_rx = {nl_rx_buf, sizeof(nl_rx_buf)};
#ifdef UE_NAS_USE_TUN
int nas_sock_fd[NUMBER_OF_UE_MAX];
#else
int nas_sock_fd;
#endif
struct msghdr nas_msg_tx;
struct msghdr nas_msg_rx;

#define GRAAL_NETLINK_ID 31

#ifdef UE_NAS_USE_TUN

static int tun_alloc(char *dev)
{
  struct ifreq ifr;
  int fd, err;

  if( (fd = open("/dev/net/tun", O_RDWR)) < 0 ) {
    printf("[TUN] failed to open /dev/net/tun\n");
    return -1;
  }

  memset(&ifr, 0, sizeof(ifr));

  /* Flags: IFF_TUN   - TUN device (no Ethernet headers)
   *        IFF_TAP   - TAP device
   *
   *        IFF_NO_PI - Do not provide packet information
   */
  ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
  if( *dev )
     strncpy(ifr.ifr_name, dev, IFNAMSIZ);

  if( (err = ioctl(fd, TUNSETIFF, (void *) &ifr)) < 0 ){
     close(fd);
     return err;
  }
  strcpy(dev, ifr.ifr_name);
  return fd;
}

int netlink_init(void)
{
  int i;
  int ret;

  char ifname[64];
  for (i = 0; i < NUMBER_OF_UE_MAX; i++) {
    sprintf(ifname, "oip%d", i+1);
    nas_sock_fd[i] = tun_alloc(ifname);

    if (nas_sock_fd[i] == -1) {
      printf("[NETLINK] Error opening socket %d (%d:%s)\n",nas_sock_fd[i],errno, strerror(errno));
      exit(1);
    }

    printf("[NETLINK]Opened socket with fd %d\n",nas_sock_fd[i]);

#if !defined(PDCP_USE_NETLINK_QUEUES)
    ret = fcntl(nas_sock_fd[i],F_SETFL,O_NONBLOCK);

    if (ret == -1) {
      printf("[NETLINK] Error fcntl (%d:%s)\n",errno, strerror(errno));
#if defined(LINK_ENB_PDCP_TO_IP_DRIVER)
      exit(1);
#endif
    }

#endif

    memset(&nas_src_addr, 0, sizeof(nas_src_addr));
    nas_src_addr.nl_family = AF_NETLINK;
    nas_src_addr.nl_pid = 1;//getpid();  /* self pid */
    nas_src_addr.nl_groups = 0;  /* not in mcast groups */
    ret = bind(nas_sock_fd[i], (struct sockaddr*)&nas_src_addr, sizeof(nas_src_addr));



    memset(&nas_dest_addr, 0, sizeof(nas_dest_addr));
    nas_dest_addr.nl_family = AF_NETLINK;
    nas_dest_addr.nl_pid = 0;   /* For Linux Kernel */
    nas_dest_addr.nl_groups = 0; /* unicast */

    // TX PART
    nas_nlh_tx=(struct nlmsghdr *)malloc(NLMSG_SPACE(NL_MAX_PAYLOAD));
    memset(nas_nlh_tx, 0, NLMSG_SPACE(NL_MAX_PAYLOAD));
    /* Fill the netlink message header */
    nas_nlh_tx->nlmsg_len = NLMSG_SPACE(NL_MAX_PAYLOAD);
    nas_nlh_tx->nlmsg_pid = 1;//getpid();  /* self pid */
    nas_nlh_tx->nlmsg_flags = 0;

    nas_iov_tx.iov_base = (void *)nas_nlh_tx;
    nas_iov_tx.iov_len = nas_nlh_tx->nlmsg_len;
    memset(&nas_msg_tx,0,sizeof(nas_msg_tx));
    nas_msg_tx.msg_name = (void *)&nas_dest_addr;
    nas_msg_tx.msg_namelen = sizeof(nas_dest_addr);
    nas_msg_tx.msg_iov = &nas_iov_tx;
    nas_msg_tx.msg_iovlen = 1;


    // RX PART
    memset(&nas_msg_rx,0,sizeof(nas_msg_rx));
    nas_msg_rx.msg_name = (void *)&nas_src_addr;
    nas_msg_rx.msg_namelen = sizeof(nas_src_addr);
    nas_msg_rx.msg_iov = &nas_iov_rx;
    nas_msg_rx.msg_iovlen = 1;
  }

  return 1;
}

#else /* UE_NAS_USE_TUN */

int netlink_init(void)
{
  int ret;

  nas_sock_fd = socket(PF_NETLINK, SOCK_RAW,GRAAL_NETLINK_ID);

  if (nas_sock_fd == -1) {
    printf("[NETLINK] Error opening socket %d (%d:%s)\n",nas_sock_fd,errno, strerror(errno));
#if defined(LINK_ENB_PDCP_TO_IP_DRIVER)
    exit(1);
#endif
  }

  printf("[NETLINK]Opened socket with fd %d\n",nas_sock_fd);

#if !defined(PDCP_USE_NETLINK_QUEUES)
  ret = fcntl(nas_sock_fd,F_SETFL,O_NONBLOCK);

  if (ret == -1) {
    printf("[NETLINK] Error fcntl (%d:%s)\n",errno, strerror(errno));
#if defined(LINK_ENB_PDCP_TO_IP_DRIVER)
    exit(1);
#endif
  }

#endif

  memset(&nas_src_addr, 0, sizeof(nas_src_addr));
  nas_src_addr.nl_family = AF_NETLINK;
  nas_src_addr.nl_pid = 1;//getpid();  /* self pid */
  nas_src_addr.nl_groups = 0;  /* not in mcast groups */
  ret = bind(nas_sock_fd, (struct sockaddr*)&nas_src_addr, sizeof(nas_src_addr));



  memset(&nas_dest_addr, 0, sizeof(nas_dest_addr));
  nas_dest_addr.nl_family = AF_NETLINK;
  nas_dest_addr.nl_pid = 0;   /* For Linux Kernel */
  nas_dest_addr.nl_groups = 0; /* unicast */

  // TX PART
  nas_nlh_tx=(struct nlmsghdr *)malloc(NLMSG_SPACE(NL_MAX_PAYLOAD));
  memset(nas_nlh_tx, 0, NLMSG_SPACE(NL_MAX_PAYLOAD));
  /* Fill the netlink message header */
  nas_nlh_tx->nlmsg_len = NLMSG_SPACE(NL_MAX_PAYLOAD);
  nas_nlh_tx->nlmsg_pid = 1;//getpid();  /* self pid */
  nas_nlh_tx->nlmsg_flags = 0;

  nas_iov_tx.iov_base = (void *)nas_nlh_tx;
  nas_iov_tx.iov_len = nas_nlh_tx->nlmsg_len;
  memset(&nas_msg_tx,0,sizeof(nas_msg_tx));
  nas_msg_tx.msg_name = (void *)&nas_dest_addr;
  nas_msg_tx.msg_namelen = sizeof(nas_dest_addr);
  nas_msg_tx.msg_iov = &nas_iov_tx;
  nas_msg_tx.msg_iovlen = 1;


  // RX PART
  memset(&nas_msg_rx,0,sizeof(nas_msg_rx));
  nas_msg_rx.msg_name = (void *)&nas_src_addr;
  nas_msg_rx.msg_namelen = sizeof(nas_src_addr);
  nas_msg_rx.msg_iov = &nas_iov_rx;
  nas_msg_rx.msg_iovlen = 1;

  return(nas_sock_fd);
}

#endif /* UE_NAS_USE_TUN */
