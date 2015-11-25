//
// Created by steppers on 20/11/15.
//

#ifndef SSIM_CHANGECONTROLLER_H
#define SSIM_CHANGECONTROLLER_H

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Observable {
protected:
    virtual void onChange(int changeId) = 0;
};

class Observer {
public:
    virtual void notify(Observable* subject, int changeId) = 0;
};

class ChangeController {
public:
    void registerForChanges(Observer* observer, Observable* subject);
    void notify(Observable* subject, int changeId);
    void distributeChanges();

private:
    unordered_map<Observable*, vector<Observer*>> _interestedParties;
    unordered_map<Observable*, set<int>> _changes;
};

#endif //SSIM_CHANGECONTROLLER_H
