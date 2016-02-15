//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_GLPANEL_H
#define SSIM_GLPANEL_H

#include "../Math/Vector2i.h"
#include "Input.h"

class GLPanel {
public:
    virtual void getGLContext() = 0;
    virtual void releaseGLContext() = 0;

    virtual bool isValid() = 0;
    virtual bool isCloseRequested() = 0;

    virtual void setResolution(int width, int height) = 0;
    virtual void setVSync(bool enabled) = 0;
    virtual void setFullscreen(bool enabled) = 0;

    virtual void update() = 0;

    Vector2i* getResolution();
    bool getVSync();
    bool isFullscreen();
    Input* getInput();

protected:
    Vector2i _resolution;
    Input* _input;
    bool _fullscreen, _vsync;
};

#endif //SSIM_GLPANEL_H
