//
// Created by Ollie on 05/11/2015.
//

#include "EnvironmentManager.h"

void EnvironmentManager::init(Engine* engine) {
    _engine = engine;
}

void EnvironmentManager::stopEngine() {
    _engine->stop();
}