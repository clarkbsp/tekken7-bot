#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include "handle.h"
#include "win32_helper.h"
#include "player.h"
#include "game.h"

HANDLE pHandle = getProcessHandle((LPCTSTR)"TEKKEN 7 ");
int main(){
    Point3d p = Point3d(1,2,3);
    Game game = Game();
    for(;;){
        game.update();
        if (GetAsyncKeyState(VK_F1) & (1 << 15)){
            std::cout << "Pressed f1 - starting scan for p1 macro state\n";
            game.initPlayerAddresses();
        }
        Sleep(200);
        system("cls");
        std::cout << game << std::endl;
    }
}