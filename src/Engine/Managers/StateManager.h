//
// Created by Ollie on 05/11/2015.
//

#ifndef SSIMCPP_STATEMANAGER_H
#define SSIMCPP_STATEMANAGER_H

#include "Manager.h"

class StateManager : Manager {
public:
    static StateManager& getInstance(){
        static StateManager instance;
        return instance;
    }

    void init();

    void setDelta(double delta);
    double getDelta();

private:
    //Singleton initialisation----------------------------------------------------
    StateManager(){}  //Keep the constructor and destructor private
    ~StateManager(){}

    StateManager(StateManager const&) = delete;   //Prevent us from using these
    void operator=(StateManager const&) = delete;
    //----------------------------------------------------------------------------

    double _delta;
};


#endif //SSIMCPP_STATEMANAGER_H
