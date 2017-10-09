/*-
 * Copyright (c) 1986, 1993
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
 *	@(#)if_arp.h	8.1 (Berkeley) 6/10/93
 * $FreeBSD$
 */

#pragma once
#include "netinet/in.h"




 /* ARP ioctl request. */
 struct arpreq {
   struct sockaddr       arp_pa;         /* protocol address             */
   struct sockaddr       arp_ha;         /* hardware address             */
   int                   arp_flags;      /* flags                        */
   struct sockaddr       arp_netmask;    /* netmask (only for proxy arps) */
   char                  arp_dev[16];

};

 struct arpreq_old {
   struct sockaddr       arp_pa;         /* protocol address             */
   struct sockaddr       arp_ha;         /* hardware address             */
   int                   arp_flags;      /* flags                        */
   struct sockaddr       arp_netmask;    /* netmask (only for proxy arps) */

};

 /* ARP Flag values. */
 #define ATF_COM         0x02            /* completed entry (ha valid)   */
 #define ATF_PERM        0x04            /* permanent entry              */
 #define ATF_PUBL        0x08            /* publish entry                */
 #define ATF_USETRAILERS 0x10            /* has requested trailers       */
 #define ATF_NETMASK     0x20            /* want to use a netmask (only
                                            for proxy entries) */
 #define ATF_DONTPUB     0x40            /* don't answer this addresses  */
 /*
  *      This structure defines an ethernet arp header.
*/

	 struct arphdr {
		    __be16   ar_hrd;         /* format of hardware address   */
	        __be16          ar_pro;         /* format of protocol address   */
	         unsigned char   ar_hln;         /* length of hardware address   */
	         unsigned char   ar_pln;         /* length of protocol address   */
	         __be16          ar_op;          /* ARP opcode (command)         */

	
};
