//
// Created by steppers on 24/11/15.
//

#include "pSystem.h"

void pSystem::setScene(pUScene* scene) {
    _scene = scene;
}

pUScene* pSystem::getScene() {
    return _scene;
}