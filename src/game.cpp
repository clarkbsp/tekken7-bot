#include <windows.h>
#include <iostream>

#include "handle.h"
#include "mem_find.h"
#include "player.h"
#include "game.h"

Game::Game(){
    initPlayerAddresses();
}

//A lazy hardcoded way to initialize the addresses for player 1 and 2 
bool Game::initPlayerAddresses(){
    unsigned long long minAddr = 0x10400264;
    unsigned long long maxAddr = 0xAFFFFFFF;//Add another F if it starts to fail; lower for faster searches
    int p1MacroStateInit = 6482; //initial neutral value for p1 macro state

    //0x10400264 is the first guess for searching for the p1 macro state address
    //The kast 2 bytes are always the same. Can try increasing first 2 bytes for faster searches
    p1.setMacroStateAddr(findAddress<int>(pHandle, p1MacroStateInit, minAddr, maxAddr, 0x10000, 4));

    if(p1.getMacroStateAddr()){
        std::cout << "p1 macro state address found\n";
        p1.setXAddr(p1.getMacroStateAddr() + 0x98c);
        p1.setYAddr(p1.getXAddr() + 0x4);
        p1.setZAddr(p1.getYAddr() + 0x4);
    }
    return true;
}