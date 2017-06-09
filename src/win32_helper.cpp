#include <windows.h>
#include "win32_helper.h"
#include <iostream>
//Functions for getting window, process, and other types of handles

HANDLE getProcessHandle(LPCTSTR windowName){
    HWND hWnd = FindWindow(NULL, windowName);
    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
    std::cout << pid <<std::endl;
    HANDLE pHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);
    if (pHandle){
        return pHandle;
    }
    return NULL;
}

HWND getWindowHandle(DWORD pid){
    EnumWindowsData data;
    data.pid = pid;
    if(!EnumWindows(EnumWindowsProc, (LPARAM)&data)){
        return data.hWnd;
    }
    return NULL;
}

HWND getWindowHandle(LPCTSTR windowName){
    return FindWindow(NULL, windowName);
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam){
    EnumWindowsData& data = *(EnumWindowsData*)lParam;
    DWORD wpid = 0;
    GetWindowThreadProcessId(hWnd, &wpid);
    if(wpid == data.pid){
        data.hWnd = hWnd;
        return FALSE;
    }
    return TRUE;
}