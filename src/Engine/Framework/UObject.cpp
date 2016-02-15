//
// Created by steppers on 23/11/15.
//

#include "UObject.h"

void UObject::addChild(UObject *child) {
    _children.push_back(child);
}

void UObject::removeChild(UObject *child) {
    //_children.erase(std::remove(_children.begin(), _children.end(), child), _children.end());
}

void UObject::addComponent(UComponent *component) {
    _components[component->getType()].push_back(component);
}