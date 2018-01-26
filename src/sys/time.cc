#include <sys/time.h>
#include <cstdint>

int gettimeofday(struct timeval *tp, struct timezone *tzp)
{
    SYSTEMTIME  system_time;
    FILETIME    file_time;
    uint64_t    time;
    const uint64_t shift = ((uint64_t)116444736000000000ULL);



    GetSystemTime(&system_time);
    SystemTimeToFileTime(&system_time, &file_time);
    time = static_cast<uint64_t>(file_time.dwLowDateTime);
    time += (static_cast<uint64_t>(file_time.dwHighDateTime)) << 32;

    tp->tv_sec = static_cast<long>((time - shift) / 10000000L);
    tp->tv_usec = static_cast<long>(system_time.wMilliseconds * 1000);
    return 0;
}
