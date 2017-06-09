
#include <iostream>
#include <windows.h>
#include "mem_find.h"
#include "win32_helper.h"
#include "player.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    //this stuff should be moved to the initPlayers function
    //player objects should be wrapped in a game class 

    Player p1;
    Player p2;
    
    

    for(;;){
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            Sleep(20);
            initPlayerAddresses(p1,p2);
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