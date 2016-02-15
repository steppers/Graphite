//
// Created by Ollie on 09/11/2015.
//

#ifndef SSIMCPP_INPUTMANAGER_H
#define SSIMCPP_INPUTMANAGER_H

#include "Manager.h"
#include "../../UI/Input.h"

class InputManager : public Manager {
public:
    static InputManager& getInstance(){
        static InputManager instance;
        return instance;
    }

    void init();
    void update();

    Input* getInput();
    void setInput(Input* input);

private:
    //Singleton initialisation----------------------------------------------------
    InputManager(){}  //Keep the constructor and destructor private
    ~InputManager(){}

    InputManager(InputManager const&) = delete;   //Prevent us from using these
    void operator=(InputManager const&) = delete;
    //----------------------------------------------------------------------------

    Input* _input;
};

#endif //SSIMCPP_INPUTMANAGER_H
