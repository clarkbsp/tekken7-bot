HANDLE getProcessHandle(LPCTSTR windowName);

struct EnumWindowsData{
        DWORD pid;
        HWND hWnd;
    };
    
HWND getWindowHandle(DWORD pid);
HWND getWindowHandle(LPCTSTR windowName);

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);