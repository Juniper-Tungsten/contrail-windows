#include <sys/resource.h>

bool validusage(int usage) {
    if ((usage == RUSAGE_SELF) || (usage == RUSAGE_CHILDREN) || (usage == RUSAGE_THREAD)||(usage == RUSAGE_BOTH))
        return true;
    else
        return false;
}

bool validlimit(int limit) {

    bool retval = false;

    switch (limit) {
        case RLIMIT_CPU:
        case RLIMIT_FSIZE:
        case RLIMIT_DATA:
        case RLIMIT_STACK:
        case RLIMIT_CORE:
        case RLIMIT_RSS:
        case RLIMIT_NPROC:
        case RLIMIT_NOFILE:
        case RLIMIT_MEMLOCK:
        case RLIMIT_AS:
        case RLIMIT_LOCKS:
        case RLIMIT_SIGPENDING:
        case RLIMIT_MSGQUEUE:
        case RLIMIT_NICE:
        case RLIMIT_RTPRIO:
        case RLIMIT_RTTIME:
        case RLIM_NLIMITS:
            retval = true;
    }

    return retval;
}

int getrusage(int usage, struct rusage *ptr) {
    if (validusage(usage) && (ptr != nullptr))
        return 0;
    else
        return -1;
}

int getrlimit(int limit, struct rlimit *ptr) {
    if (validlimit(limit) && (ptr != nullptr))
        return 0;
    else
        return -1;
}

int setrlimit(int limit, struct rlimit const *ptr) {
    if (validlimit(limit) && (ptr != nullptr))
        return 0;
    else
        return -1;
}
