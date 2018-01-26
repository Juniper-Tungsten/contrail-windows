#include <unistd.h>
#include <windows.h>
#include <TlHelp32.h>

unsigned int sleep(unsigned int seconds) { 
    ::Sleep(1000 * seconds);
    return 0;
}

int usleep(useconds_t usec) {
    ::Sleep((usec + 999U) / 1000U); // divide by 1000 and round up
    return 0;
}

//review if this needs to be in a try-catch
int getppid() {
    HANDLE hSnapshot = INVALID_HANDLE_VALUE;
    PROCESSENTRY32 pe32;

    DWORD parentid = 0, pid=0;
    
    pid = GetCurrentProcessId();

    hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (INVALID_HANDLE_VALUE == hSnapshot)
            return -1;

    memset(&pe32, 0, sizeof(pe32));
    pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hSnapshot, &pe32))
        return -1;

    do {
        if (pe32.th32ProcessID == pid) {
            parentid = pe32.th32ParentProcessID;
            break;
        }
    } while (Process32Next(hSnapshot, &pe32));

    if (hSnapshot != INVALID_HANDLE_VALUE)
        CloseHandle(hSnapshot);

    return parentid;
}

long sysconf(int name) {
    return -1;
}

pid_t vfork(void) {
    return -1;
}
