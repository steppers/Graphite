//
// Created by steppers on 04/11/15.
//

#include "Vector2i.h"
#include "../Engine/Managers/StateManager/StateManager.h"

Vector2i::Vector2i() {
    _x = 0;
    _y = 0;
}

Vector2i::Vector2i(int x, int y) {
    _x = x;
    _y = y;
}

Vector2i* Vector2i::add(int x, int y) {
    _x += x;
    _y += y;
    onChange(XY);
    return this;
}

Vector2i* Vector2i::add(Vector2i* other) {
    _x += other->getX();
    _y += other->getY();
    onChange(XY);
    return this;
}

int Vector2i::getX() {
    return _x;
}

int Vector2i::getY() {
    return _y;
}

void Vector2i::set(int x, int y) {
    _x = x; _y = y;
    onChange(XY);
}

void Vector2i::setX(int x) {
    _x = x;
    onChange(X);
}

void Vector2i::setY(int y) {
    _y = y;
    onChange(Y);
}

void Vector2i::onChange(int changeId) {
    StateManager::getInstance().notify(this, changeId);
}

void Vector2i::notify(Observable *subject, int changeId) {
    switch(changeId){
        case changeType::X:
            _x = ((Vector2i*)subject)->getX();
            break;
        case changeType::Y:
            _y = ((Vector2i*)subject)->getY();
            break;
        case changeType::XY:
            _x = ((Vector2i*)subject)->getX();
            _y = ((Vector2i*)subject)->getY();
            break;
    }
}