#include <windows.h>
#include <iostream>

#include "handle.h"
#include "mem_find.h"
#include "player.h"
#include "game.h"

Game::Game(){
    initPlayerAddresses();
}

bool Game::initPlayerAddresses(){
    unsigned long long minAddr = 0x10400264;//The first guess for searching for the p1 macro state address
    unsigned long long maxAddr = 0xBFFFFFFF;//Increase if it starts to fail; lower for faster searches
    int p1MacroStateInit = 6482; //initial neutral value for p1 macro state

    p1.macroStateAddr = (findAddress<int>(pHandle, p1MacroStateInit, 
        minAddr, maxAddr, 0x10000, 4));

    if(p1.macroStateAddr){
        std::cout << "p1 macro state address found\n";

        p1.animStateAddr = (p1.macroStateAddr + 0x10c);
        p1.attackStateAddr = (p1.macroStateAddr + 0xA8);
        p1.blockStateAddr = (p1.macroStateAddr + 0xB0);

        p1.xAddr = (p1.macroStateAddr + 0x98c);
        p1.yAddr = (p1.xAddr + 0x4);
        p1.zAddr = (p1.yAddr + 0x4);

        unsigned long long p2MinAddr = ((p1.macroStateAddr >> 16) << 16) + 0x68fc;
        p2.macroStateAddr = (findAddress<int>(pHandle, p1MacroStateInit, 
            p2MinAddr, maxAddr, 0x10000, 4));

        if(p2.macroStateAddr){
            p2.animStateAddr = (p2.macroStateAddr + 0x10c - 8);
            p2.xAddr = (p2.macroStateAddr + 0x98c-8);//different offset with opponent p2
            p2.yAddr = (p2.yAddr + 0x4);
            p2.zAddr = (p2.zAddr + 0x4);  
        }
    }
    return true;
}

void Game::update(){
    p1.update();
    p2.update();
}