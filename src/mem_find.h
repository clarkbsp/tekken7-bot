template<typename T>
DWORD64 findAddress(HANDLE& pHandle, T targetVal, unsigned long long initAddr,
                    unsigned long long  maxAddr, int stepSize, int nBytes)
{
    T testVal;
    for(auto addr = initAddr; addr < maxAddr; addr+= stepSize){
        ReadProcessMemory(pHandle, (void*)addr, &testVal, nBytes, 0);
        //std::cout << testVal << std::endl;
        if(testVal == targetVal){
            std::cout << addr << std::endl;
            return addr;
        }
    }
    return 0;
};