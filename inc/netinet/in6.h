/*-
 * Copyright (C) 1995, 1996, 1997, and 1998 WIDE Project.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the project nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	$KAME: in6.h,v 1.89 2001/05/27 13:28:35 itojun Exp $
 */

/*-
 * Copyright (c) 1982, 1986, 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)in.h	8.3 (Berkeley) 1/3/94
 * $FreeBSD$
 */


#ifndef _NETINET6_IN6_H_
#define _NETINET6_IN6_H_

/*
*	IPv6 address structure
*/

#include <winsock2.h>
#include <sys/wintypes.h>

//#if __UAPI_DEF_IN6_ADDR
struct linux_in6_addr {
    union {
        u_char  Byte[16];
        u_short Word[8];
        u_int   Dword[4];
    } u;

#define s6_addr16		u.Word
#define s6_addr32		u.Dword
};
//#endif /* __UAPI_DEF_IN6_ADDR */

#if __UAPI_DEF_SOCKADDR_IN6
struct sockaddr_in6 {
	unsigned short int	sin6_family;    /* AF_INET6 */
	__be16			sin6_port;      /* Transport layer port # */
	__be32			sin6_flowinfo;  /* IPv6 flow information */
	struct linux_in6_addr		sin6_addr;      /* IPv6 address */
	__u32			sin6_scope_id;  /* scope id (new in RFC2553) */
};
#endif /* __UAPI_DEF_SOCKADDR_IN6 */

#if __UAPI_DEF_IPV6_MREQ
struct ipv6_mreq {
	/* IPv6 multicast address of group */
	struct linux_in6_addr ipv6mr_multiaddr;

	/* local IPv6 address of interface */
	int		ipv6mr_ifindex;
};
#endif /* __UAPI_DEF_IVP6_MREQ */

#define ipv6mr_acaddr	ipv6mr_multiaddr

struct in6_flowlabel_req {
	struct linux_in6_addr	flr_dst;
	__be32	flr_label;
	__u8	flr_action;
	__u8	flr_share;
	__u16	flr_flags;
	__u16 	flr_expires;
	__u16	flr_linger;
	__u32	__flr_pad;
	/* Options in format of IPV6_PKTOPTIONS */
};

#endif /* !_NETINET6_IN6_H_ */
