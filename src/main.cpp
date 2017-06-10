#include <iostream>
#include <windows.h>

#include "handle.h"
#include "win32_helper.h"
#include "player.h"
#include "game.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    
    Game game = Game();
    for(;;){
        game.update();
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            game.initPlayerAddresses();
        }
        Sleep(100);
        //std::cout << game.p1.getMacroState() << " " << game.p2.getMacroState() << std::endl;
        //std::cout << game.p1.getMacroState()<< " " << game.p2.getMacroState()<< " " << game.p2.getX() << " " << game.p2.getY()  << " " << game.p2.getZ() << std::endl;

        std:: cout << game.p1.getAttackState() << " " << game.p1.getBlockState()<< std::endl;
    }
}