//
// Created by steppers on 24/11/15.
//

#ifndef SSIM_UCOMPONENT_H
#define SSIM_UCOMPONENT_H

enum ComponentType {
    GEOMETRY_COMPONENT,
    GRAPHICS_COMPONENT,
    LOGIC_COMPONENT,
    TRANSFORM_COMPONENT
};

class pUComponent {
public:
    pUComponent(ComponentType type);
    int getType();

private:
    ComponentType _type;
};


#endif //SSIM_UCOMPONENT_H
