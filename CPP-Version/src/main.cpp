#include "UI/Window.h"
#include "Util/SThread.h"
#include "Util/BlockingQueue.h"

#include <math.h>
#include <iostream>

using namespace std;

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
            i += 0.08;
            SThread::sleep(16);
            w->update();
            if(w->getInput()->isKeyDown(GLFW_KEY_ESCAPE) | w->isCloseRequested())
                break;
        }

        delete w;
    }
};

BlockingQueue<int> _queue;

class Producer : public SRunnable {
public:
    void run(SThread* thread) {
        for(int i = 0; i < 10; i++)
        {
            _queue.add(i);
            SThread::sleep(250);
        }
    }
};

class Consumer : public SRunnable {
public:
    void run(SThread* thread) {
        for(int i = 0; i < 10; i++)
        {
            cout << _queue.take() << endl;
        }
    }
};

//class Producer : public Task {
//public:
//    void execute(TaskRunnable* runnable){
//        for(int i = 0; i < 10; i++)
//        {
//            _queue.add(i);
//            SThread::sleep(250);
//        }
//    }
//};
//
//class Consumer : public Task {
//public:
//    void execute(TaskRunnable* runnable){
//        for(int i = 0; i < 10; i++)
//        {
//            cout << _queue.take() << endl;
//        }
//    }
//};

int main(void) {
//    TestRunnable r;
//    SThread t(&r);
//    t.start();
//    t.join();

    Consumer consumer;
    Producer producer;
    SThread p(&producer);
    SThread c(&consumer);

    c.start();
    p.start();

    c.join();
    p.join();

//    TaskManager tm = TaskManager::getInstance();
//    tm.init();
//
//    tm.submitTask(new Consumer());
//    tm.submitTask(new Producer());

    return 0;
}