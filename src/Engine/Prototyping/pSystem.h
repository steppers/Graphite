//
// Created by steppers on 24/11/15.
//

#ifndef SSIM_PSYSTEM_H
#define SSIM_PSYSTEM_H

#include "../Managers/TaskManager/Task.h"
#include "pUObject.h"
#include "pUScene.h"

class pSystem : public Task {
public:
    virtual void execute(TaskThread* taskThread) = 0;
    void setScene(pUScene* root);

protected:
    pUScene* getScene();

private:
    pUScene* _scene;
};

#endif //SSIM_PSYSTEM_H