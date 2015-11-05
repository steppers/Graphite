//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASKTHREAD_H
#define SSIMCPP_TASKTHREAD_H

#include <thread>
#include "Task.h"

using namespace std;

class TaskThread {
public:
    TaskThread(int threadId);

    int getThreadId();
    void endThread();

    Task* getTask();
    void setTask(Task* task);

private:
    thread _thread;
    int _threadId;
    Task* _task;
};

#endif //SSIMCPP_TASKTHREAD_H
