#include <windows.h>
#include <iostream>
DWORD64 findAddress(HANDLE& pHandle, DWORD targetVal, DWORD64 init, DWORD64 max, DWORD64 step, int nBytes){
    DWORD testVal;
    for(DWORD64 addr = init; addr < max; addr+= step){
        ReadProcessMemory(pHandle, (void*)addr, &testVal, nBytes, 0);
        //std::cout << testVal << std::endl;
        if(testVal == targetVal){
            std::cout << addr << std::endl;
            return addr;
        }
    }
    return 0;
}