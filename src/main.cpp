#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#include <windows.h>

#include <iostream>
#include <stdlib.h>
#include <time.h> 

#include "handle.h"
#include "win32_helper.h"
#include "keyboard.h"
#include "player.h"
#include "game.h"
#include "game_input.h"
#include "action.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    srand (time(NULL));
    Game game = Game();
    GameInput gi = GameInput(false);
    std::cout << Action::actionStrings[64] << "\n";
    std::string randomAction;
    for(;;){
        game.update();
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            game.initPlayerAddresses();
        }
        else if (GetAsyncKeyState(VK_F2) & (1 << 15)){
            randomAction = Action::actionStrings[rand() % 99];
            std::cout << randomAction << "\n";
            gi.setReversed(game.p1.sideSwapped);
            gi.sendInput(randomAction);

            Sleep(30);
        }

        Sleep(100);
        //system("cls");
        //std::cout << game << std::endl;
    }
}