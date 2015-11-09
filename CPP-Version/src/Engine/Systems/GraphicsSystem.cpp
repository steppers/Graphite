//
// Created by steppers on 09/11/15.
//

#include "GraphicsSystem.h"

#include "../Managers/EnvironmentManager.h"
#include <math.h>

GraphicsSystem::GraphicsSystem(int width, int height) {
    _window = new Window(width, height);
}

GraphicsSystem::~GraphicsSystem() {
    delete _window;
}

void GraphicsSystem::execute(TaskThread *taskThread) {
    if(!_window->isValid()) {
        EnvironmentManager::getInstance().stopEngine();
        Engine::getLogger()->logMessage("Graphics", "ERROR: Cannot create window!");
    }

    _window->getContext();
    c = (0.5*sin(i))+0.5;
    glClearColor(c, c, 0, 1);
    i += 0.08;
    SThread::sleep(16);
    _window->update();
    if(_window->getInput()->isKeyDown(GLFW_KEY_ESCAPE) | _window->isCloseRequested())
        EnvironmentManager::getInstance().stopEngine();
}