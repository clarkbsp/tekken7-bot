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
    updateGeometry2d();
}

Point2d Player::getCentroid2d() const{
    int count = 0;
    float xSum = 0;
    float ySum = 0;
    for (auto&& point : geometry2d){
        xSum += point.x;
        ySum += point.y;
        count += 1;
    }

    return Point2d(xSum/count, ySum/count);
}

Point2d Player::getPosition2d() const{
    return position2d;
}

float Player::getX() const{
    return position2d.x;
}

float Player::getY() const{
    return position2d.y;
}
void Player::updateGeometry2d(){
    geometry2d.clear();
    int stepSize = 32;
    int numPoints = 23;
    auto minAddr = xAddr;
    auto maxAddr = xAddr + stepSize*numPoints;
    float tempX;
    float tempY;
    for (auto addr = minAddr; addr < maxAddr; addr += stepSize){
        ReadProcessMemory(pHandle, (void*)(addr), &tempX, 4, 0);
        ReadProcessMemory(pHandle, (void*)(addr+8), &tempY, 4, 0);
        geometry2d.push_back(Point2d(tempX,tempY));
    }
    position2d = getCentroid2d();
}

std::ostream& operator<<(std::ostream& os, const Player& p){
    os << "Base Address: " << std::hex << p.macroStateAddr << std::endl;
    os << "Geometry Address: " << std::hex << p.xAddr << std::endl;
    os << "States: " << std:: dec << p.macroState << " " << p.animState << " " << p.attackState<< " " << p.blockState << std::endl;
    os << "Position: " << p.getPosition2d();//<< p.x << " " << p.y << " " << p.z;

    return os;
}