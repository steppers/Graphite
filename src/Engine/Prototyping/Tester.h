//
// Created by steppers on 04/12/15.
//

#ifndef R_ENGINE_TESTER_H
#define R_ENGINE_TESTER_H


#include "../Managers/TaskManager/TaskManager.h"

class Thread : public SThread {
public:
    Thread(int threadId);
    ~Thread();

    int getThreadId();
    void stopThread();

private:
    int _id;

    class TaskRunnable : public SRunnable {
    public:
        void run(SThread* thread) {
            while(_running) {
                if(_task == nullptr)
                    continue;
                else {
                    _task->execute((TaskThread*)thread);
                }
            }
        }

        TestTask* _task;
        void stop(){ _running = false; }
    private:
        bool _running = true;
    };

    TaskRunnable _runnable;
};

class TestTask {
public:
    virtual void execute(TaskThread* taskThread);
};

class GraphicsSys : public TestTask {
public:
    void execute(TaskThread* taskThread);
};

class LoopSys : public TestTask {
public:
    void execute(TaskThread* taskThread);
};

class Tester {
public:
    Tester();
    ~Tester();

    void start();

private:
    SThread* threads[];

    GraphicsSys graphicsSys;
    LoopSys loopSys;
};

#endif //R_ENGINE_TESTER_H
