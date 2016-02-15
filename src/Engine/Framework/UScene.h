//
// Created by steppers on 23/11/15.
//

#ifndef SSIM_USCENE_H
#define SSIM_USCENE_H

#include <vector>
#include "UObject.h"

using namespace std;

class UScene {
public:
    void addChild(UObject* child);
    void removeChild(UObject* child);

private:
    vector<UObject*> _children;
};


#endif //SSIM_USCENE_H
