#include <time.h>
#include <sys/times.h>

clock_t times(struct tms *buf) {
    if (buf != nullptr) {
        buf->tms_utime = clock();
        buf->tms_stime = buf->tms_cutime = buf->tms_cstime = 0;
    }

    return buf->tms_stime;
}
