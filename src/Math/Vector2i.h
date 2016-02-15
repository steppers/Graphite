//
// Created by steppers on 04/11/15.
//

#ifndef SSIMCPP_VECTOR2I_H
#define SSIMCPP_VECTOR2I_H


#include "../Engine/Managers/StateManager/ChangeController.h"

class Vector2i : public Observer, public Observable{
public:
    Vector2i();
    Vector2i(int x, int y);

    Vector2i* add(int x, int y);
    Vector2i* add(Vector2i* other);

    int getX();
    int getY();

    void set(int x, int y);
    void setX(int x);
    void setY(int y);

    void notify(Observable* subject, int changeId);

private:
    int _x, _y;

    void onChange(int changeId);

    enum changeType {
        X,
        Y,
        XY
    };
};


#endif //SSIMCPP_VECTOR2I_H
