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

    p1.setMacroStateAddr(findAddress<int>(pHandle, p1MacroStateInit, 
        minAddr, maxAddr, 0x10000, 4));

    if(p1.getMacroStateAddr()){
        std::cout << "p1 macro state address found\n";

        p1.setAnimStateAddr(p1.getMacroStateAddr() + 0x10c);
        p1.setAttackStateAddr(p1.getMacroStateAddr() + 0xA8);
        p1.setBlockStateAddr(p1.getMacroStateAddr() + 0xB0);

        p1.setXAddr(p1.getMacroStateAddr() + 0x98c);
        p1.setYAddr(p1.getXAddr() + 0x4);
        p1.setZAddr(p1.getYAddr() + 0x4);

        unsigned long long p2MinAddr = ((p1.getMacroStateAddr() >> 16) << 16) + 0x68fc;
        p2.setMacroStateAddr(findAddress<int>(pHandle, p1MacroStateInit, 
            p2MinAddr, maxAddr, 0x10000, 4));

        if(p2.getMacroStateAddr()){
            p2.setAnimStateAddr(p2.getMacroStateAddr() + 0x10c - 8);
            p2.setXAddr(p2.getMacroStateAddr() + 0x98c-8);//different offset with opponent p2
            p2.setYAddr(p2.getXAddr() + 0x4);
            p2.setZAddr(p2.getYAddr() + 0x4);  
        }
    }
    return true;
}