//
// Created by steppers on 04/11/15.
//

#include "Engine.h"
#include "Managers/EnvironmentManager.h"
#include "Managers/StateManager.h"

Engine::Engine() {
    initManagers();
}

void Engine::initManagers() {
    TaskManager::getInstance().init();
    EnvironmentManager::getInstance().init(this);
    StateManager::getInstance().init();
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
    }
}

void Engine::addSystem(System* system) {
    _systems.push_back(system);
}

void Engine::getLogger() {

}

void Engine::debugMode(bool enabled) {

}