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
#include "game_input.h"
#include "game.h"
#include "action.h"
#include "learning_agent.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    srand (time(NULL));
    bool running = false;
    Game game = Game();
    //GameInput gi = GameInput(false);
    LearningAgent la = LearningAgent(game);
    //std::cout << Action::actionStrings[64] << "\n";
    //std::string randomAction;
    
    for(;;){
        la.game.update();
        if (running == true){
            la.game.gameInput.setReversed(la.game.p1.sideSwapped);
            la.update();
        }
        
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            la.game.initPlayerAddresses();
        }
        else if (GetAsyncKeyState(VK_F2) & (1 << 15)){
            //randomAction = Action::actionStrings[rand() % 99];
            //std::cout << randomAction << "\n";
            //game.gameInput.setReversed(game.p1.sideSwapped);
            //game.gameInput.sendInput(randomAction);

            Sleep(30);
        }
        else if (GetAsyncKeyState(VK_F3) & (1 << 15)){
            //la.update();
            running ^= true;
            Sleep(50);
        }

        Sleep(30);
        //system("cls");
        //std::cout << la.game << std::endl;
    }
}