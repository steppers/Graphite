//
// Created by steppers on 04/11/15.
//

#ifndef SSIMCPP_VECTOR2I_H
#define SSIMCPP_VECTOR2I_H


class Vector2i {
public:
    Vector2i(int x, int y);

    Vector2i add(int x, int y);
    Vector2i add(Vector2i* other);

    int getX();
    int getY();

    void setX(int x);
    void setY(int y);

private:
    int _x, _y;
};


#endif //SSIMCPP_VECTOR2I_H
