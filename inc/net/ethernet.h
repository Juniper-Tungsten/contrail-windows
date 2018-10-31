/*
 * Fundamental constants relating to ethernet.
 *
 * $FreeBSD$
 *
 */

#ifndef _NET_ETHERNET_H_
#define _NET_ETHERNET_H_

#include "sys/wintypes.h"

#define ETH_ALEN   6
#define ETHERTYPE_VLAN (0x8100)

#define ETHERTYPE_IPV4  0x0800
#define ETHERTYPE_IPV6  0x86dd

#define ETHER_ADDR_LEN 6

struct ether_addr {
    unsigned char ether_addr_octet[ETH_ALEN];
};

#endif /* !_NET_ETHERNET_H_ */
