//
// Created by steppers on 20/11/15.
//

#include "GLPanel.h"

Vector2i* GLPanel::getResolution() {
    return &_resolution;
}

bool GLPanel::getVSync() {
    return _vsync;
}

bool GLPanel::isFullscreen() {
    return _fullscreen;
}

Input* GLPanel::getInput() {
    return _input;
}