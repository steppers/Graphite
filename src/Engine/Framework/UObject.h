//
// Created by steppers on 23/11/15.
//

#ifndef SSIM_UOBJECT_H
#define SSIM_UOBJECT_H

#include <vector>
#include <unordered_map>
#include "UComponent.h"

using namespace std;

class UObject {
public:
    void addChild(UObject* child);
    void removeChild(UObject* child);

    void addComponent(UComponent* component);

private:
    unordered_map<int, vector<UComponent*>> _components;
    vector<UObject*> _children;
};


#endif //SSIM_UOBJECT_H
