#include "UI/Window.h"

int main() {
    Window* w = new Window(300, 300);
    if(!w->isValid())
        return -1;

    w->getContext();
    glClearColor(1, 0, 0, 1);

    while(true)
    {
        w->update();
        if(w->getInput()->isKeyDown(GLFW_KEY_ESCAPE) | w->isCloseRequested())
            break;
    }

    delete w;

    return 0;
}