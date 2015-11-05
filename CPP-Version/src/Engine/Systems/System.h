//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_SYSTEM_H
#define SSIMCPP_SYSTEM_H

#include "../Managers/TaskManager/Task.h"

class System : Task
{
public:
    virtual void execute();
};

#endif //SSIMCPP_SYSTEM_H
