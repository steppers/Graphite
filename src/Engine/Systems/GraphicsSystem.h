//
// Created by steppers on 09/11/15.
//

#ifndef SSIMCPP_GRAPHICSSYSTEM_H
#define SSIMCPP_GRAPHICSSYSTEM_H

#include "System.h"
#include "../../UI/GLPanel.h"

class GraphicsSystem : public System {
public:
    GraphicsSystem(int width, int height);
    ~GraphicsSystem();

    void execute(TaskThread* taskThread);

    void setVSync(bool enabled);

private:
    GLPanel* _window;
    double i = 0, c = 0;

    long fps = 0;
};


#endif //SSIMCPP_GRAPHICSSYSTEM_H
