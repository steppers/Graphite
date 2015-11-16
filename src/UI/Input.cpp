//
// Created by steppers on 04/11/15.
//

#include "Input.h"

void Input::setKeyStatus(int key, int scancode, int action, int mods) {
    _keys[key] = action;
}

bool Input::isKeyDown(int key) {
    return _keys[key] == GLFW_PRESS;
}

bool Input::isKeyUp(int key) {
    return _keys[key] == (GLFW_RELEASE | 0);
}

void Input::poll() {
    glfwPollEvents();
}