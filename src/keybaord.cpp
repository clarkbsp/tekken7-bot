#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0502
#endif
#include <windows.h>
#include "keyboard.h"

Keyboard::Keyboard(){
    kbInput.type = INPUT_KEYBOARD;
    kbInput.ki.wScan = 0;
    kbInput.ki.time = 0;
    kbInput.ki.dwExtraInfo = 0;
}

void Keyboard::keyPress(int key){
    keyDown(key);
    Sleep(32);
    keyUp(key);
}

void Keyboard::keyDown(int key){
    key = MapVirtualKey(key, 0);
    kbInput.ki.dwFlags = KEYEVENTF_SCANCODE;
    kbInput.ki.wScan = key;
    SendInput(1, &kbInput, sizeof(INPUT));
}

void Keyboard::keyUp(int key){
    key = MapVirtualKey(key, 0);
    kbInput.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
    kbInput.ki.wScan = key;
    SendInput(1, &kbInput, sizeof(INPUT));
}