//
// Created by steppers on 05/11/15.
//

#include "TaskManager.h"
#include "TerminateTask.h"

TaskManager::TaskManager() { }
TaskManager::~TaskManager() { }

void TaskManager::init() {
    int numCores = thread::hardware_concurrency();
    for(int i = 0; i < numCores; i++)
    {
        _threads.push_back(new TaskThread(i, this));
    }
}

void TaskManager::submitTask(Task *task) {
    _tasks.add(task);
}

void TaskManager::submitTasks(vector<Task*> tasks) {
    for(Task* t : tasks)
        _tasks.add(t);
}

void TaskManager::killThreads() {
    for(TaskThread* t : _threads)
        _tasks.add(new TerminateTask());
    for(TaskThread* t : _threads)
        t->join();
}

void TaskManager::waitForTasks() {

}

Task* TaskManager::takeTask() {
    return _tasks.take();
}