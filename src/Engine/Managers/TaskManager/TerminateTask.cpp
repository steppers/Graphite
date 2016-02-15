//
// Created by Ollie on 06/11/2015.
//

#include "TerminateTask.h"

void TerminateTask::execute(TaskThread* taskThread){
    taskThread->kill();
}