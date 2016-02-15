//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_SYSTEM_H
#define SSIMCPP_SYSTEM_H

#include "../Managers/TaskManager/Task.h"
#include "../Managers/TaskManager/TaskManager.h"
#include "../Framework/UObject.h"
#include "../Framework/UScene.h"

class System : public Task
{
public:
    virtual void execute(TaskThread* taskThread) = 0;
    void setUScene(UScene* scene){
        _scene = scene;
    };

protected:
    UScene* _scene;
};

#endif //SSIMCPP_SYSTEM_H
