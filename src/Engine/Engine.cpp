//
// Created by steppers on 04/11/15.
//

#include "Engine.h"
#include "Managers/EnvironmentManager.h"
#include "Managers/InputManager.h"
#include "Managers/PlatformManager.h"
#include "Managers/ServiceManager.h"
#include "Managers/StateManager/StateManager.h"

Logger Engine::_logger;

Engine::Engine() {
    initManagers();
}

Engine::~Engine() {
    TaskManager::getInstance().killThreads();
    for(System* s : _systems)
        delete s;
}

void Engine::initManagers() {
    TaskManager::getInstance().init();
    EnvironmentManager::getInstance().init(this);
    StateManager::getInstance().init();
    InputManager::getInstance().init();
    PlatformManager::getInstance().init();
    ServiceManager::getInstance().init();
}

void Engine::start() {
    _running = true;
    loop();
}

void Engine::stop() {
    _mutexRunning.lock();   //Synchronize for thread safety
        _running = false;
    _mutexRunning.unlock();//-----------------------------
}

void Engine::loop() {
    while(true)
    {
        _mutexRunning.lock();//Synchronize for thread safety
        if(!_running){
            _mutexRunning.unlock();
            break;
        }_mutexRunning.unlock();//------------------------

        for(System* s : _systems)
            _scheduler.submitTask((Task*)s);
        _scheduler.executeTasks();
        _scheduler.waitForTaskCompletion();

        InputManager::getInstance().update();
        StateManager::getInstance().distributeChanges();

        if(EnvironmentManager::getInstance().getDebugMode())
            if(InputManager::getInstance().getInput()->isKeyDown(GLFW_KEY_ESCAPE))
                stop();
    }
}

void Engine::addSystem(System* system) {
    _systems.push_back(system);
}

Logger* Engine::getLogger() {
    return &_logger;
}

void Engine::debugMode(bool enabled) {
    EnvironmentManager::getInstance().setDebugMode(enabled);
    _logger.debugEnable(enabled);
}