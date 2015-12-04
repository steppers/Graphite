//
// Created by steppers on 04/12/15.
//

#ifndef R_ENGINE_TESTER_H
#define R_ENGINE_TESTER_H

#include "../../Util/SThread.h"
#include "../../Util/BlockingQueue.h"
#include <iostream>

using namespace std;

class Thread;

class TestTask {
public:
    virtual void execute(Thread* taskThread) = 0;
};

class Thread : public SThread {
public:
    Thread(int threadId, BlockingQueue<TestTask*>* queue);
    ~Thread();

    int getThreadId();
    void stopThread();

private:
    int _id;

    class TaskRunnable : public SRunnable {
    public:
        void run(SThread* thread) {
            while(_running) {
                TestTask* task = _queue->take();
                task->execute((Thread*)thread);
            }
        }
        void stop(){ _running = false; }
        void setQueue(BlockingQueue<TestTask*>* queue) { _queue = queue; }
    private:
        bool _running = true;
        BlockingQueue<TestTask*>* _queue;
    };

    TaskRunnable _runnable;
};

class TerminateTask : public TestTask {
public:
    void execute(Thread* taskThread) {
        taskThread->stopThread();
    }
};

class GraphicsSys : public TestTask {
public:
    int life = 0;
    void execute(Thread* taskThread){
        cout << "Life:" << life++ << " [Graphics]" << endl;
    }
};

class LoopSys : public TestTask {
public:
    int life = 0;
    void execute(Thread* taskThread) {
        cout << "Life:" << life++ << " [Game Loop]" << endl;
    }
};

class Tester {
public:
    Tester();
    ~Tester();

    void Start();

private:
    Thread* _threads[2];
    BlockingQueue<TestTask*> _queue;

    GraphicsSys _graphicsSys;
    LoopSys _loopSys;

    TerminateTask _terminateTask;
};

#endif //R_ENGINE_TESTER_H
