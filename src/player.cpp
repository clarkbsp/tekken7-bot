#include <windows.h>
#include <iostream>
#include "mem_find.h"
#include "player.h"

Player::Player(){
    macroState = 0;
}

//A lazy hardcoded way to initialize the addresses for player 1 and 2 
bool initPlayerAddresses(Player& p1, Player& p2){
    unsigned long long maxAddr = 0xFFFFFFFF;//Add another F if it starts to fail; lower for faster searches
    int p1MacroStateInit = 6482; //initial neutral value for p1 macro state
    extern HANDLE pHandle;
    p1.macroStateAddr = 0x10400264; //Last 2 bytes are always the same. Can try increasing first 2 bytes for faster searches
    p1.macroState = 0;
    p1.macroStateAddr = findAddress<int>(pHandle, p1MacroStateInit, 0x10400264, maxAddr, 0x10000, 4);

    if(p1.macroStateAddr){
    //put these inside the init players function
        std::cout << "p1 macro state address found\n";
        p1.xAddr = p1.macroStateAddr + 0x98c;
        p1.yAddr = p1.xAddr + 0x4;
        p1.zAddr = p1.yAddr + 0x4;
    }
    return TRUE;
}