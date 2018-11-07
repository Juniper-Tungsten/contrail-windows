/*-
 * Copyright (c) 1982, 1986, 1993
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
 *	@(#)resource.h	8.4 (Berkeley) 1/9/95
 * $FreeBSD$
 */

#ifndef _SYS_RESOURCE_H_
#define	_SYS_RESOURCE_H_


#include <stdint.h>
#include <posix_time.h>

#define RLIMIT_CPU     0
#define RLIMIT_FSIZE     1
#define RLIMIT_DATA     2
#define RLIMIT_STACK     3
#define RLIMIT_CORE     4
#define RLIMIT_RSS     5
#define RLIMIT_NPROC     6
#define RLIMIT_NOFILE     7
#define RLIMIT_MEMLOCK     8
#define RLIMIT_AS     9
#define RLIMIT_LOCKS     10
#define RLIMIT_SIGPENDING     11
#define RLIMIT_MSGQUEUE     12
#define RLIMIT_NICE     13 
#define RLIMIT_RTPRIO     14
#define RLIMIT_RTTIME     15
#define RLIM_NLIMITS     16

#define	RUSAGE_SELF     0
#define	RUSAGE_CHILDREN     (-1)
#define RUSAGE_BOTH      (-2)
#define	RUSAGE_THREAD     1

struct rlimit {
    uint32_t rlim_cur;
    uint32_t rlim_max;
};

struct	rusage {
    struct timeval ru_utime;	/* user time used */
    struct timeval ru_stime;	/* system time used */
    long	ru_maxrss;		/* max resident set size */
#define	ru_first	ru_ixrss
    long	ru_ixrss;		/* integral shared memory size */
    long	ru_idrss;		/* integral unshared data " */
    long	ru_isrss;		/* integral unshared stack " */
    long	ru_minflt;		/* page reclaims */
    long	ru_majflt;		/* page faults */
    long	ru_nswap;		/* swaps */
    long	ru_inblock;		/* block input operations */
    long	ru_oublock;		/* block output operations */
    long	ru_msgsnd;		/* messages sent */
    long	ru_msgrcv;		/* messages received */
    long	ru_nsignals;		/* signals received */
    long	ru_nvcsw;		/* voluntary context switches */
    long	ru_nivcsw;		/* involuntary " */
#define	ru_last		ru_nivcsw
};

int getrusage(int, struct rusage *);
int getrlimit(int resource, struct rlimit *rlp);
int setrlimit(int resource, const struct rlimit *rlp);

#endif	/* !_SYS_RESOURCE_H_ */
