//
// Created by steppers on 04/11/15.
//

#include "Vector2i.h"

Vector2i::Vector2i() {
    _x = 0;
    _y = 0;
}

Vector2i::Vector2i(int x, int y) {
    _x = x;
    _y = y;
}

int Vector2i::getX() {
    return _x;
}

int Vector2i::getY() {
    return _y;
}

void Vector2i::set(int x, int y) {
    _x = x; _y = y;
}

void Vector2i::setX(int x) {
    _x = x;
}

void Vector2i::setY(int y) {
    _y = y;
}