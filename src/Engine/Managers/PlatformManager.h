//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_PLATFORMMANAGER_H
#define SSIM_PLATFORMMANAGER_H

#include "../../UI/GLPanel.h"
#include "../../UI/Input.h"

class PlatformManager {
public:
    static PlatformManager& getInstance(){
        static PlatformManager instance;
        return instance;
    }

    void init();

    static GLPanel* createGLPanel(int width, int height);
    static Input* getInput(GLPanel* panel);

private:
    //Singleton initialisation----------------------------------------------------
    PlatformManager(){}  //Keep the constructor and destructor private
    ~PlatformManager(){}

    PlatformManager(PlatformManager const&) = delete;   //Prevent us from using these
    void operator=(PlatformManager const&) = delete;
    //----------------------------------------------------------------------------
};


#endif //SSIM_PLATFORMMANAGER_H
