#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif

#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "handle.h"
#include "win32_helper.h"
#include "player.h"
#include "game.h"
#include "keyboard.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
Keyboard kb;
int main(){
    Game game = Game();
    for(;;){
        game.update();
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            game.initPlayerAddresses();
        }
        else if (GetAsyncKeyState(VK_F2) & (1 << 15)){
            std::cout << "Sending lp\n";
            kb.keyPress(keymap::lp);
        }
        Sleep(200);
        system("cls");
        std::cout << game << std::endl;
    }
}