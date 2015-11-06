#include "UI/Window.h"
#include "Engine/Managers/TaskManager/TaskManager.h"

#include <math.h>
#include <iostream>

using namespace std;

class WindowTask : public Task {
public:
    void execute(TaskThread* taskThread){
        Window* w = new Window(300, 300);
        if(!w->isValid())
            return;

        w->getContext();

        double i = 0, c = 0;
        while(true)
        {
            c = (0.5*sin(i))+0.5;
            glClearColor(c, c, 0, 1);
            i += 0.08;
            SThread::sleep(16);
            w->update();
            if(w->getInput()->isKeyDown(GLFW_KEY_ESCAPE) | w->isCloseRequested())
                break;
        }

        delete w;
    }
};

class OutputTask : public Task {
public:
    void execute(TaskThread* taskThread){
        for(int i = 0; i < 20; i++) {
            cout << i << endl;
            SThread::sleep(1000);
        }
    }
};

int main(void) {
    TaskManager& tm = TaskManager::getInstance();
    tm.init();

    tm.submitTask(new WindowTask());
    tm.submitTask(new OutputTask());

    tm.killThreads();

    return 0;
}