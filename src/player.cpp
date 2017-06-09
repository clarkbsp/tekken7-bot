#include <windows.h>
#include "player.h"

Player::Player(){
    macroState = 0;
}

//A lazy hardcoded way to initialize the addresses for player 1 and 2 
bool initPlayerAddresses(Player& p1, Player& p2){

    p1.macroStateAddr = 0x10400264; 
    p1.macroState = 0;

    return 1;
}