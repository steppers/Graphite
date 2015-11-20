//
// Created by steppers on 09/11/15.
//

#include "GraphicsSystem.h"

#include "../Managers/EnvironmentManager.h"
#include "../Managers/PlatformManager.h"
#include <math.h>

GraphicsSystem::GraphicsSystem(int width, int height) {
    _window = PlatformManager::createGLPanel(width, height);
}

GraphicsSystem::~GraphicsSystem() {
    delete _window;
}

void GraphicsSystem::execute(TaskThread *taskThread) {
    if(!_window->isValid()) {
        EnvironmentManager::getInstance().stopEngine();
        Engine::getLogger()->logMessage("Graphics", "ERROR: Cannot create window!");
    }

    Engine::getLogger()->logMessage("FPS", to_string(fps++));

    _window->getGLContext();  //Ready the thread for rendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Rendering code here
    c = (0.5*sin(i))+0.5;   //Update clear color
    glClearColor(0, c, c, 1);
    i += 0.08;

    //Update the window here.
    _window->update();
    if(_window->isCloseRequested())
        EnvironmentManager::getInstance().stopEngine();

    _window->releaseGLContext();  //Release the GL context
}

void GraphicsSystem::setVSync(bool enabled) {
    _window->setVSync(enabled);
}