//
// Created by steppers on 04/11/15.
//

#ifndef SSIMCPP_WINDOW_H
#define SSIMCPP_WINDOW_H

#include <GLFW/glfw3.h>

#include "../Math/Vector2i.h"
#include "Input.h"

class Window {
public:
    Window(int width, int height);
    ~Window();

    void getContext();
    void releaseContext();
    void update();

    bool isCloseRequested();
    bool isValid();

    void setResolution(int width, int height);
    void setFullscreen(bool enabled);
    void setVSync(bool enabled);
    void setTitle(string title);

    Vector2i* getResolution();
    bool isFullscreen();
    bool isVSyncEnabled();

    Input* getInput();

private:
    //Member objects
    Vector2i* _resolution;
    GLFWwindow* _window;
    Input* _input;

    //Member variables
    bool _fullscreen, _vsync;

    bool _validWindow = false;

    void init();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        ((Input*)glfwGetWindowUserPointer(window))->setKeyStatus(key, scancode, action, mods);
    }
};

#endif //SSIMCPP_WINDOW_H
