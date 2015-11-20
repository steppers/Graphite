//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_PCWINDOW_H
#define SSIM_PCWINDOW_H


#include <GLFW/glfw3.h>
#include "../GLPanel.h"

class PCWindow : public GLPanel {
public:
    PCWindow(int width, int height);
    ~PCWindow();

    void getGLContext();
    void releaseGLContext();

    bool isValid();

    void update();
    bool isCloseRequested();

    void setResolution(int width, int height);
    void setVSync(bool enabled);
    void setFullscreen(bool enabled);

private:
    GLFWwindow* _window;
    bool _validWindow = false;

    void init();

    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        ((Input*)glfwGetWindowUserPointer(window))->setKeyStatus(key, scancode, action, mods);
    }
};


#endif //SSIM_PCWINDOW_H
