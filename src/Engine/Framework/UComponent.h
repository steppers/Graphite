//
// Created by steppers on 24/11/15.
//

#ifndef SSIM_UCOMPONENT_H
#define SSIM_UCOMPONENT_H

enum UComponentType {
    TRANSFORM_COMPONENT,
    GRAPHICS_COMPONENT,
    GEOMETRY_COMPONENT,
    LOGIC_COMPONENT
};

class UComponent {
public:
    UComponent(UComponentType type);
    UComponentType getType();

private:
    UComponentType _type;
};

#endif //SSIM_UCOMPONENT_H
