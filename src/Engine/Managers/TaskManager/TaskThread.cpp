//
// Created by Ollie on 06/11/2015.
//

#include "TaskThread.h"
#include "TaskManager.h"

TaskThread::TaskThread(int id, TaskManager* taskManager)
:SThread(this){
    _id = id;
    _tm = taskManager;
    start();
}

void TaskThread::run(SThread* thread){
    _running = true;
    while(_running){
        _tm->takeTask()->execute(this);
        _tm->notifyOfTaskCompletion();
    }
}

int TaskThread::getThreadId(){
    return _id;
}

void TaskThread::kill() {
    _running = false;
}