#include <posix_stdlib.h>

int getloadavg(double loadavg[], int nelem) {
    if (loadavg == nullptr || nelem <= 0)
        return -1;
    for(int i = 0; i < nelem; ++i)
        loadavg[i] = 1.;
    return 1;//one sample
}
