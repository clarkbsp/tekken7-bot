#include <iostream>
#include <windows.h>

#include "handle.h"
#include "win32_helper.h"
#include "player.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    
    Player p1;
    Player p2;
    initPlayerAddresses(p1,p2);
    for(;;){
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            Sleep(20);
            initPlayerAddresses(p1,p2);
        }
        Sleep(100);
        std::cout << p1.getMacroState() << " " << p1.getX() << " " << p1.getY()  << " " << p1.getZ() << std::endl;
    }
}