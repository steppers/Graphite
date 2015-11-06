//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASKMANAGER_H
#define SSIMCPP_TASKMANAGER_H

#include "../Manager.h"
#include "Task.h"

class TaskManager : Manager {
public:
    void init();

    void submitTask(Task* task);

};

#endif //SSIMCPP_TASKMANAGER_H
