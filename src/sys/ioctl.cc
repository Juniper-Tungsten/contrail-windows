#include <sys/ioctl.h>

#include <windows.h>

int ioctl(int fd, unsigned long request, ...) {
    va_list vl;
    if(request == TIOCGWINSZ) {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        struct winsize *sz;
        va_start(vl, request);
        sz = va_arg(vl, struct winsize *);
        va_end(vl);
        if(sz == nullptr)
            return -1;
        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) != 0) {
            sz->ws_col = csbi.srWindow.Right - csbi.srWindow.Left + 1;
            sz->ws_row = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            return 0;
        }
    }
    return -1;
}
