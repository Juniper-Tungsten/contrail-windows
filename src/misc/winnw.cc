#include <net/if.h>
#include <net/ethernet.h>

struct if_nameindex* if_nameindex() {
    return nullptr;
}

void if_freenameindex(struct if_nameindex*) {
}

struct ether_addr* ether_aton(const char*) {
    return nullptr;
}
