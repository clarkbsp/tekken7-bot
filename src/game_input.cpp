#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#include <windows.h>
#include <string>

#include "keyboard.h"
#include "game_input.h"

GameInput::GameInput(bool reversed){
    setReversed(reversed);
    up = keymap::up;
    down = keymap::down;
    lp = keymap::lp;
    rp = keymap::rp;
    lk = keymap::lk;
    rk = keymap::rk;
}
int GameInput::charToKeymap(char c){
    switch(c){
        case 'u':
            return up;
            break;
        case 'd':
            return down;
            break;
        case 'f':
            return forward;
            break;
        case 'b':
            return backward;
            break;
        case '1':
            return lp;
            break;      
        case '2':
            return rp;
            break;
        case '3':
            return lk;
            break;
        case '4':
            return rk;
            break;       
        default:
            return 0;
    }
}

void GameInput::sendInput(std::string inputString){
    if (inputString == ""){ return; }
    for(char& c : inputString){
        kb.keyDown(charToKeymap(c));
    }
    Sleep(32);
    for(char& c : inputString){
        kb.keyUp(charToKeymap(c));
    }
}

void GameInput::setReversed(bool reversed){
    if (reversed){
        forward = keymap::left;
        backward = keymap::right;
    }
    else{
        forward = keymap::right;
        backward = keymap::left;
    }
}