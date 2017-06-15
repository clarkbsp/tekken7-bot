#include <windows.h>
#include <iostream>
#include <sstream>
#include <cmath>

#include "handle.h"
#include "mem_find.h"
#include "player.h"
#include "game.h"

Game::Game(){
    damageDoneDiff = 0;
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

        p1.healthAddr = p1.macroStateAddr + 0xf62;

        p1.sideSwappedAddr = p1.macroStateAddr + 0x860;

        p1.xAddr = (p1.macroStateAddr + 0x98c);
        p1.yAddr = (p1.xAddr + 0x8);
        p1.zAddr = (p1.xAddr + 0x4);

        unsigned long long p2MinAddr = ((p1.macroStateAddr >> 16) << 16) + 0x68fc;
        p2.macroStateAddr = (findAddress<int>(pHandle, p1MacroStateInit, 
            p2MinAddr, maxAddr, 0x10000, 4));

        if(p2.macroStateAddr){
            p2.animStateAddr = (p2.macroStateAddr + 0x10c - 8); //(p2.macroStateAddr + 0x10c - 8);
            p2.xAddr = (p2.macroStateAddr + 0x98c-8);//different offset with opponent p2
            p2.yAddr = (p2.xAddr + 0x8);
            p2.zAddr = (p2.xAddr + 0x4);

            p2.attackStateAddr = (p2.macroStateAddr + 0xA0);
            p2.blockStateAddr = (p2.macroStateAddr + 0xB0 - 8);

            p2.healthAddr = p2.macroStateAddr + 0xf62-8;

            p2.sideSwappedAddr = p2.macroStateAddr + 0xf40;
        }
    }
    return true;
}

int Game::getDamageDoneDiff() const{
    return damageDoneDiff;
}

std::string Game::getGameStateString() const{
    return gameStateString;
}

float Game::getPlayerDistance() const{
    return playerDistance;
}

int Game::getQuantizedPlayerDistance() const{
    int quantizedDistance = (int)getPlayerDistance()/200;
    return std::min(9,(std::max(0,quantizedDistance-5)));
}

void Game::update(){
    //Make sure to update players first
    updatePlayers();
    updatePlayerDistance();
    updateQuantizedPlayerDistance();

    //Update state string last
    updateGameStateString();
}

void Game::updatePlayers(){
    int p1HealthDelta = p1.getHealth();
    int p2HealthDelta = p2.getHealth();

    p1.update();
    p2.update();

    p1HealthDelta -= p1.getHealth();
    p2HealthDelta -= p2.getHealth();
    damageDoneDiff = p2HealthDelta - p1HealthDelta;
}

void Game::updateGameStateString(){
    std::stringstream ss;
    ss << std::hex;
    ss << p1.getStateString();
    ss << " ";
    ss << p2.getStateString();
    ss << " ";
    ss << quantizedPlayerDistance;
    gameStateString = ss.str();
}

void Game::updatePlayerDistance(){
    playerDistance = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
}

void Game::updateQuantizedPlayerDistance(){
    int quantizedDistance = (int)getPlayerDistance()/200;
    quantizedPlayerDistance =  std::min(9,(std::max(0,quantizedDistance-5)));   
}

std::ostream& operator<<(std::ostream& os, const Game& g){
    os << "Player 1:\n" << g.p1 << std::endl;
    os << "\n";
    os << "Player 2:\n" << g.p2 << std::endl;
    os << "\n";
    os << "Player Distance: " << g.playerDistance << std::endl;
    os << "Quantized Player Distance: " << g.getQuantizedPlayerDistance() << std::endl;
    os << "Difference in Damage Dealt: " << g.getDamageDoneDiff();
    os << "\nGame State String: " << g.gameStateString;
    return os;
}