//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASK_H
#define SSIMCPP_TASK_H

class TaskThread;
class Task
{
public:
    virtual void execute(TaskThread* taskThread) = 0;
};

#endif //SSIMCPP_TASK_H
