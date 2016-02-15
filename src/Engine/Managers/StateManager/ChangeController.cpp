//
// Created by steppers on 20/11/15.
//

#include "ChangeController.h"

void ChangeController::registerForChanges(Observer *observer, Observable *subject) {
    _interestedParties[subject].push_back(observer);
}

void ChangeController::notify(Observable *subject, int changeId) {
    _changes[subject].insert(changeId);
}

void ChangeController::distributeChanges() {
    for(auto it = _changes.begin(); it != _changes.end(); ++it)
    {
        for(int change : it->second)
        {
            for(Observer* obs : _interestedParties[it->first])
            {
                obs->notify(it->first, change);
            }
        }
    }
}