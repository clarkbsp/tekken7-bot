#include <windows.h>
#include <iostream>

#include "handle.h"
#include "mem_find.h"
#include "player.h"

Player::Player(){
}

void Player::update(){
    ReadProcessMemory(pHandle, (void*)(xAddr), &x,4, 0);
    ReadProcessMemory(pHandle, (void*)(yAddr), &y,4, 0);
    ReadProcessMemory(pHandle, (void*)(zAddr), &z,4, 0);
    ReadProcessMemory(pHandle, (void*)(macroStateAddr), &macroState,4, 0);
    ReadProcessMemory(pHandle, (void*)(animStateAddr), &animState,4, 0);
    ReadProcessMemory(pHandle, (void*)(attackStateAddr), &attackState,4, 0);
    ReadProcessMemory(pHandle, (void*)(blockStateAddr), &blockState,4, 0);
}