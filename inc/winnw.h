#pragma once


struct if_nameindex;
unsigned int  windows_if_nametoindex(char const * name);
void  windows_if_freenameindex(struct if_nameindex *nameindex);
struct if_nameindex *  windows_if_nameindex(void);
char *windows_if_indextoname(unsigned int ifindex, char *ifname);
