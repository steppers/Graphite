//
// Created by steppers on 04/11/15.
//

#ifndef SSIMCPP_ENGINE_H
#define SSIMCPP_ENGINE_H


#include "Systems/System.h"
#include "Framework/Scheduler.h"
#include <vector>
//#include <mutex>

using namespace std;

class Engine {
public:
    Engine();
    ~Engine();

    void start();
    void stop();

    void addSystem(System* system);
    void getLogger();
    void debugMode(bool enabled);

private:
    //Member Objects
    vector<System*> _systems;
    Scheduler _scheduler;

    //std::mutex _mutexRunning;
    bool _running = false;

    void initManagers();
    void loop();
};


#endif //SSIMCPP_ENGINE_H
