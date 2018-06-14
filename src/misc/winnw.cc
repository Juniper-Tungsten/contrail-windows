#include "winutils.h"
#include "winnw.h"
#include "net/ethernet.h"
#include <intrin.h> 
#include <Iphlpapi.h>

#define ASCII_0 ('0')
#define ASCII_a ('a')
#define ASCII_A ('A')

static inline int GetValueOfHexChar(char c) {
    unsigned int val = 0;
    if (c >= ASCII_A) {
        val = static_cast<unsigned int>(c - ASCII_A);
        if (val <= 5) return val + 10;
    }
    else if (c >= ASCII_a) {
        val = static_cast<unsigned int>(c - ASCII_a);
        if (val <= 5) return val + 10;
    }
    else if (c >= ASCII_0) {
        val = static_cast<unsigned int>(c - ASCII_0);
        if (val <= 9) return val;
    }
    return -1;
}

unsigned int  windows_if_nametoindex(char const* name) {
    return ::if_nametoindex(name);
}
void if_freenameindex(struct if_nameindex* nameindex) {
    ::free(nameindex);
}
struct if_nameindex* if_nameindex(void) {
    return nullptr;
}

char* windows_if_indextoname(unsigned int ifindex, char* ifname) {
    return ::if_indextoname(ifindex, ifname);
}

struct ether_addr* ether_aton_r(const char *str, struct ether_addr * addr) {
    int i, highernibble, lowernibble;

    if (str == nullptr || addr == nullptr)
        return nullptr;

    if (str[ETHER_ADDR_LEN] != '0')
        return nullptr;

    std::string addrstr(str);

    if (addrstr.length() != ETHER_ADDR_LEN)
        return nullptr;
    i = 0;

    while(i < ETHER_ADDR_LEN) {
        highernibble = GetValueOfHexChar(addrstr[i]);
        if (-1 == highernibble)
            return nullptr;
        i++;

        lowernibble = GetValueOfHexChar(addrstr[i]);
        if ( -1 == lowernibble)
            return nullptr;
        i++;
        addr->ether_addr_octet[i] = static_cast<u_int8_t>(lowernibble);
        addr->ether_addr_octet[i] += static_cast<u_int8_t>(highernibble << 4);

        if (addrstr[i] != ':')
            return nullptr;
        i++;
    }
     return addr;
}

struct ether_addr* ether_aton(const char* asc) {
    static struct ether_addr addr;
    return ether_aton_r(asc, &addr);
}

u_int32_t custom_htonl(u_int32_t x) {
    u_char* s = (u_char*)&x;
    u_int32_t retval = s[3];
    retval |= s[2] << 8;
    retval |= s[1] << 16;
    retval |= s[0] << 24;
    return retval;
}
