//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_SCHEDULER_H
#define SSIMCPP_SCHEDULER_H


#include "../Managers/TaskManager/Task.h"
#include "../Managers/TaskManager/TaskManager.h"

#include <vector>

using namespace std;

class Scheduler {
public:
    Scheduler();

    void submitTask(Task* task);
    void executeTasks();
    void waitForTaskCompletion();

private:
    vector<Task*> _tasks;
    TaskManager* _tm;
};


#endif //SSIMCPP_SCHEDULER_H
