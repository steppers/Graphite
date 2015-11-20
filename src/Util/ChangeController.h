//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_CHANGECONTROLLER_H
#define SSIM_CHANGECONTROLLER_H

class ChangeController {
public:
    void registerForChange(Observer* observer, SharedObject* object);
    void notifyOfChange(SharedObject* object);

    void distributeChanges();

private:

};
template <typename T>
class SharedObject {
public:
    T* getCopy() {
        
    }
private:
    T val;
};

class ObservedObject {
public:

};

class Observer {
public:
    virtual void onChange();
};

#endif //SSIM_CHANGECONTROLLER_H
