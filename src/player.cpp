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

unsigned long long Player::getAnimStateAddr(){
    return animStateAddr;
}
void Player::setAnimStateAddr(unsigned long long addr){
    animStateAddr = addr;
}

unsigned long long Player::getAttackStateAddr(){
    return animStateAddr;
}
void Player::setAttackStateAddr(unsigned long long addr){
    attackStateAddr = addr;
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

int Player::getAnimState(){
    ReadProcessMemory(pHandle, (void*)(animStateAddr), &animState,4, 0);
    return animState;
}

int Player::getAttackState(){
    ReadProcessMemory(pHandle, (void*)(attackStateAddr), &attackState,4, 0);
    return attackState;
}