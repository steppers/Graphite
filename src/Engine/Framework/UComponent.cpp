//
// Created by steppers on 24/11/15.
//

#include "UComponent.h"

UComponent::UComponent(UComponentType type) {
    _type = type;
}

UComponentType UComponent::getType() {
    return _type;
}