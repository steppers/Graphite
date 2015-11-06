//
// Created by steppers on 05/11/15.
//

#include "Scheduler.h"

Scheduler::Scheduler() {
    //_tm = &TaskManager::getInstance();
}

void Scheduler::submitTask(Task *task) {
    _tasks.push_back(task);
}

void Scheduler::executeTasks() {
    //_tm->submitTasks(&_tasks);
    _tasks.clear();
}

void Scheduler::waitForTaskCompletion() {

}