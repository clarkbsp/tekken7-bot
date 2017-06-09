#include <windows.h>
#include <iostream>

#include "handle.h"
#include "mem_find.h"
#include "player.h"

Player::Player(){
}

unsigned long long Player::getXAddr(){
    return xAddr;
}

void Player::setXAddr(unsigned long long addr){
    xAddr = addr;
}

unsigned long long Player::getYAddr(){
    return yAddr;
}
void Player::setYAddr(unsigned long long addr){
    yAddr = addr;
}

unsigned long long Player::getZAddr(){
    return zAddr;
}
void Player::setZAddr(unsigned long long addr){
    zAddr = addr;
}

unsigned long long Player::getMacroStateAddr(){
    return macroStateAddr;
}
void Player::setMacroStateAddr(unsigned long long addr){
    macroStateAddr = addr;
}

float Player::getX(){
    ReadProcessMemory(pHandle, (void*)(xAddr), &x,4, 0);
    return x;
}

float Player::getY(){
    ReadProcessMemory(pHandle, (void*)(yAddr), &y,4, 0);
    return y;
}

float Player::getZ(){
    ReadProcessMemory(pHandle, (void*)(zAddr), &z,4, 0);
    return z;
}

int Player::getMacroState(){
    ReadProcessMemory(pHandle, (void*)(macroStateAddr), &macroState,4, 0);
    return macroState;
}

//A lazy hardcoded way to initialize the addresses for player 1 and 2 
bool initPlayerAddresses(Player& p1, Player& p2){
    unsigned long long minAddr = 0x10400264;
    unsigned long long maxAddr = 0xFFFFFFFF;//Add another F if it starts to fail; lower for faster searches
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
    return TRUE;
}