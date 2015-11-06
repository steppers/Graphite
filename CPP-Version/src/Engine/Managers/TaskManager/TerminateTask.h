//
// Created by Ollie on 06/11/2015.
//

#ifndef SSIMCPP_TERMINATETASK_H
#define SSIMCPP_TERMINATETASK_H


#include "TaskThread.h"
#include "Task.h"

class TerminateTask : public Task {
public:
    void execute(TaskThread* taskThread);
};


#endif //SSIMCPP_TERMINATETASK_H
