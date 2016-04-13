//
// Created by steppers on 16/02/16.
//

#ifndef _PSCHEDULER_H
#define _PSCHEDULER_H

#include <vector>
#include "PThread.h"

using namespace std;

class PScheduler {
public:
    PScheduler(int numThreads);
    ~PScheduler();
private:
    vector<PThread*> _threads;
    int numThreads = 0;
};

#endif //_PSCHEDULER_H
