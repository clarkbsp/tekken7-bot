
#include <iostream>
#include <windows.h>
#include "win32_helper.h"
#include "player.h"
#include "mem_find.h"
int main(){
    //this stuff should be moved to the initPlayers function
    //player objects should be wrapped in a game class 
    unsigned long long maxAddr = 0xFFFFFFFF;//Add another F if it starts to fail
    int p1MacroStateInit = 6482; //initial neutral value for macro state
    Player p1;
    Player p2;
    
    HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");

    for(;;){
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            Sleep(20);
            initPlayerAddresses(p1,p2);
            //this should be a get function not an assignment
            p1.macroStateAddr = findAddress<int>(pHandle, p1MacroStateInit, 0x10400264, maxAddr, 0x10000, 4);
            if(p1.macroStateAddr){
                //put these inside the init players function
                std::cout << "p1 macro state address found\n";
                p1.xAddr = p1.macroStateAddr + 0x98c;
                p1.yAddr = p1.xAddr + 0x4;
                p1.zAddr = p1.yAddr + 0x4;
            }

        }
        //offload these to get functions
        ReadProcessMemory(pHandle, (void*)(p1.macroStateAddr), &p1.macroState,4 ,0);
        ReadProcessMemory(pHandle, (void*)(p1.xAddr), &p1.x,4, 0);
        ReadProcessMemory(pHandle, (void*)(p1.yAddr), &p1.y,4, 0);
        ReadProcessMemory(pHandle, (void*)(p1.zAddr), &p1.z,4, 0);
        Sleep(100);
        std::cout << p1.macroState<< " " << p1.x << " " << p1.y  << " " << p1.z << std::endl;
    }
}