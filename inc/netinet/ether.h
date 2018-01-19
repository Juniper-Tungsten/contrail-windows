/*
 * Fundamental constants relating to ethernet.
 *
 * $FreeBSD$
 *
 */

#ifndef _NET_ETHERNET_H_
#define _NET_ETHERNET_H_

#include <net/ethernet.h>

struct ether_addr *ether_aton(const char *asc);
char *ether_ntoa(const struct ether_addr *addr);

#endif /* !_NET_ETHERNET_H_ */
