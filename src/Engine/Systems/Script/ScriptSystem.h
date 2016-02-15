//
// Created by os4g14 on 15/02/16.
//

#ifndef R_ENGINE_SCRIPTSYSTEM_H
#define R_ENGINE_SCRIPTSYSTEM_H


#include "../System.h"
#include "../../../UI/GLPanel.h"

class ScriptSystem : public System {
public:
    ScriptSystem();
    ~ScriptSystem();

    void execute(TaskThread* taskThread);
private:

};

#endif //R_ENGINE_SCRIPTSYSTEM_H
