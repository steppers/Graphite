//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASK_H
#define SSIMCPP_TASK_H

#include "TaskThread.h"

class Task
{
public:
    virtual void execute(TaskThread thread);
};

#endif //SSIMCPP_TASK_H
