/*
 * Fundamental constants relating to ethernet.
 *
 * $FreeBSD$
 *
 */

#ifndef __NET_ETHERNET_H___
#define __NET_ETHERNET_H___

#include <net/ethernet.h>

struct ether_addr *ether_aton(const char *asc);

#endif /* !__NET_ETHERNET_H___ */
