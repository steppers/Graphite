#include "UI/Window.h"
#include "Util/SThread.h"

#include <math.h>

class TestRunnable : public SRunnable {
public:
    void run(SThread* thread) {
        Window* w = new Window(300, 300);
        if(!w->isValid())
            return;

        w->getContext();

        double i = 0, c = 0;
        while(true)
        {
            c = (0.5*sin(i))+0.5;
            glClearColor(c, 0, 0, 1);
            i += 0.01;
            SThread::sleep(2);
            w->update();
            if(w->getInput()->isKeyDown(GLFW_KEY_ESCAPE) | w->isCloseRequested())
                break;
        }

        delete w;
    }
};

int main(void) {
    TestRunnable r;
    SThread t(&r);
    t.start();
    t.join();

    return 0;
}