template<typename T>
unsigned long long findAddress(const HANDLE& pHandle, 
                                T targetVal, 
                                unsigned long long minAddr,
                                unsigned long long  maxAddr, 
                                int stepSize, 
                                int nBytes){
    T testVal;
    for(auto addr = minAddr; addr < maxAddr; addr+= stepSize){
        ReadProcessMemory(pHandle, (void*)addr, &testVal, nBytes, 0);
        if(testVal == targetVal){
            return addr;
        }
    }
    return 0;
};