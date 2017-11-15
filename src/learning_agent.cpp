#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#include <windows.h>
#include <cmath>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "keyboard.h"
#include "game_input.h"
#include "player.h"
#include "game.h"
#include "action.h"
#include "learning_agent.h"
LearningAgent::LearningAgent(Game& game){
    discountRate = 0.75;
    learningRate = 0.1;
    //rewards.push_back(0);//Sets R_0 to 0
    timeStep = 0;
    stepSize = 20;
    game = game;
    srand (time(NULL));
}

double LearningAgent::getQ(std::string state, std::string action){
    std::string key = state + " " + action;
    if (qVals.count(key) == 0){
        qVals[key] = 0;
    }
    return qVals[key];

    
}

std::string LearningAgent::getGreedyAction(std::string state){
    std::string greedyAction = getRandomAction(); //defaults to random
    double greedyActionQ = -1000000;
    for(auto& action : Action::actionStrings){
        double q = getQ(state, action); 
        if(q > greedyActionQ){
            greedyAction = action;
            greedyActionQ = q;
        }
    }
    return greedyAction;
}
std::string LearningAgent::getEpsilonGreedyAction(std::string state){
    if((rand() % 10) < 1){
        return getRandomAction();
    }
    return getGreedyAction(state);
}

std::string LearningAgent::getRandomAction(){
    return Action::actionStrings[rand() % Action::actionStrings.size()];
}

double LearningAgent::getReturn(int timeToUpdate){
    double totalReturn = 0;
    for(auto i = timeToUpdate + 1; i < timeToUpdate+stepSize; i++){
        totalReturn += pow(discountRate,i-timeToUpdate-1)*rewards[i];
    }
    return totalReturn;
}

double LearningAgent::getReward(){
    return game.getDamageDoneDiff();// - 1;///7;//Temporary. Only works for player1
}
std::string LearningAgent::getState(){
    return game.getGameStateString();
}
void LearningAgent::update(){
    //Take e-greedy action
    //store state and action
    auto state = getState();
    states.push_back(state);
    auto action = getEpsilonGreedyAction(state);
    actionsTaken.push_back(action);
    //Take action
    takeAction(action);
    game.update(); //
    rewards.push_back(getReward());
    //std::cout<< rewards[timeStep] <<std::endl;
    //std::cout<< states[timeStep] <<std::endl;
    
    //std::cout << timeStep << std::endl;
    int timeToUpdate = timeStep - stepSize + 0 ;
    if(timeToUpdate >= 0){
        auto totalReturn = getReturn(timeToUpdate);
        totalReturn = totalReturn 
            + pow(discountRate,stepSize)
            * getQ(states[timeToUpdate+stepSize], actionsTaken[timeToUpdate+stepSize]);
        updateQ(states[timeToUpdate], actionsTaken[timeToUpdate], totalReturn);
    }
    //auto qv = qVals["abc 1"] = 100;
    //qVals["abc 2"] = 101;
    //auto ga = getGreedyAction("abc");
    //std::cout << ga << " " << qv << "\n";
    std::cout<< "Action : " << actionsTaken[timeStep] <<std::endl;
    timeStep += 1;
}

void LearningAgent::updateQ(std::string state, std::string action, double totalReturn){
    std::string key = state + " " + action;
    if (qVals.count(key) == 0){
        qVals[key] = 0;
    }
    auto qv = qVals[key];
    qVals[key] = qv + learningRate*(totalReturn - qv);
    //std::cout << key << ": " << qVals[key] << std::endl;
}
void LearningAgent::takeAction(std::string action){
    game.gameInput.sendInput(action);
}