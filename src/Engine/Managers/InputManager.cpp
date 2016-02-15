//
// Created by Ollie on 09/11/2015.
//

#include "InputManager.h"

void InputManager::init() { }

void InputManager::update() {
    _input->poll();
}

void InputManager::setInput(Input *input) {
    _input = input;
}

Input* InputManager::getInput() {
    return _input;
}
