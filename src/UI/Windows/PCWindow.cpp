//
// Created by steppers on 20/11/15.
//

#include "PCWindow.h"
#include "../../Engine/Managers/InputManager.h"

PCWindow::PCWindow(int width, int height) {
    _resolution.setX(width);
    _resolution.setY(height);

    _input = new Input();

    InputManager::getInstance().setInput(_input);
    init();
}

PCWindow::~PCWindow() {
    if(_validWindow)
    {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }
    delete _input;
}

void PCWindow::init() {
    if (!glfwInit()){
        _validWindow = false;
        return;
    }

    _window = glfwCreateWindow(_resolution.getX(), _resolution.getY(), "-*|S|*-", NULL, NULL);
    if(!_window)
    {
        glfwTerminate();
        _validWindow = false;
        return;
    }
    glfwSetWindowUserPointer(_window, _input);  //Assign out input object to this window

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(0);

    glfwSetKeyCallback(_window, key_callback);
    glfwMakeContextCurrent(nullptr);

    _validWindow = true;
}

void PCWindow::getGLContext() {
    glfwMakeContextCurrent(_window);
}

void PCWindow::releaseGLContext() {
    glfwMakeContextCurrent(nullptr);
}

bool PCWindow::isValid() {
    return _validWindow;
}

void PCWindow::update() {
    glfwSwapBuffers(_window);
}

bool PCWindow::isCloseRequested() {
    return glfwWindowShouldClose(_window) == GL_TRUE;
}

void PCWindow::setResolution(int width, int height) {
    _resolution.set(width, height);
    //TODO: Finish resolution set function for PC
}

void PCWindow::setVSync(bool enabled) {
    _vsync = enabled;
    GLFWwindow* cur = glfwGetCurrentContext();
    glfwMakeContextCurrent(_window);
    glfwSwapInterval(_vsync ? 1 : 0);
    glfwMakeContextCurrent(cur);
}

void PCWindow::setFullscreen(bool enabled) {
    _fullscreen = enabled;
    //TODO: Finish fullscreen function for PC
}