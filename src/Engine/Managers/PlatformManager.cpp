//
// Created by steppers on 20/11/15.
//

#include "PlatformManager.h"
#include "../../UI/Windows/PCWindow.h"

void PlatformManager::init() { }

GLPanel* PlatformManager::createGLPanel(int width, int height) {
    return new PCWindow(width, height);
    //TODO: Finish the create GLPanel function for other platforms
}