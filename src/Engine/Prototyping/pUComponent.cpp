//
// Created by steppers on 24/11/15.
//

#include "pUComponent.h"

pUComponent::pUComponent(ComponentType type) {
    _type = type;
}

int pUComponent::getType() {
    return _type;
}