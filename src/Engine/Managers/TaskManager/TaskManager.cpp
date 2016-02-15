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
    _mutex.lock();
    _totalTasks++;
    _mutex.unlock();
}

void TaskManager::submitTasks(vector<Task*>* tasks) {
    for(Task* t : *tasks)
        _tasks.add(t);
    _mutex.lock();
    _totalTasks += tasks->size();
    _mutex.unlock();
}

void TaskManager::killThreads() {
    for(TaskThread* t : _threads)
        _tasks.add(new TerminateTask());
    for(TaskThread* t : _threads)
        t->join();
}

void TaskManager::waitForTasks() {
    unique_lock<mutex> lock(_mutex);
    while(_totalTasks > 0) {    //Wait for no more tasks being executed
        _cond.wait(lock);
    }
}

Task* TaskManager::takeTask() {
    return _tasks.take();
}

void TaskManager::notifyOfTaskCompletion() {
    _mutex.lock();
    _totalTasks--;
    _cond.notify_one();
    _mutex.unlock();
}