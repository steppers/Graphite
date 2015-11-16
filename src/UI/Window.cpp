//
// Created by steppers on 04/11/15.
//

#include "Window.h"
#include "../Engine/Managers/InputManager.h"

Window::Window(int width, int height) {
    _resolution = new Vector2i(width, height);
    _input = new Input();
    InputManager::getInstance().setInput(_input);
    init();
}

Window::~Window() {
    if(_validWindow)
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }

    delete _resolution;
    delete _input;
}

void Window::init() {
    if (!glfwInit()){
        _validWindow = false;
        return;
    }

    _window = glfwCreateWindow(_resolution->getX(), _resolution->getY(), "-*|S|*-", NULL, NULL);
    if(!_window)
    {
        glfwTerminate();
        _validWindow = false;
        return;
    }
    glfwSetWindowUserPointer(_window, _input);  //Assign out input object to this window

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(_window, key_callback);
    glfwMakeContextCurrent(nullptr);

    _validWindow = true;
}

void Window::getContext() {
    glfwMakeContextCurrent(_window);
}

void Window::releaseContext() {
    glfwMakeContextCurrent(nullptr);
}

void Window::update() {
    glfwSwapBuffers(_window);
}

bool Window::isCloseRequested() {
    return glfwWindowShouldClose(_window) == GL_TRUE;
}

bool Window::isValid() {
    return _validWindow;
}

Input* Window::getInput() {
    return _input;
}