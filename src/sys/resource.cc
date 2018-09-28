#include <sys/resource.h>

int getrusage(int, struct rusage *) {
    return -1;
}

int getrlimit(int, struct rlimit *) {
    return -1;
}

int setrlimit(int, struct rlimit const *) {
    return -1;
}
