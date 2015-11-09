//
// Created by steppers on 04/11/15.
//

#ifndef SSIMCPP_INPUT_H
#define SSIMCPP_INPUT_H

#include <GLFW/glfw3.h>
#include <unordered_map>

using namespace std;

class Input {
public:
    Input(){};

    void setKeyStatus(int key, int scancode, int action, int mods);

    bool isKeyDown(int key);
    bool isKeyUp(int key);

    static void poll();

private:
    unordered_map<int, int> _keys;
};


#endif //SSIMCPP_INPUT_H
