template<typename T>
DWORD64 findAddress(HANDLE& pHandle, T targetVal, DWORD64 init, DWORD64 max, DWORD step, DWORD nBytes)
{
    T testVal;
    for(DWORD64 addr = init; addr < max; addr+= step){
        ReadProcessMemory(pHandle, (void*)addr, &testVal, nBytes, 0);
        //std::cout << testVal << std::endl;
        if(testVal == targetVal){
            std::cout << addr << std::endl;
            return addr;
        }
    }
    return 0;
};