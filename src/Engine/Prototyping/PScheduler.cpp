//
// Created by steppers on 16/02/16.
//

#include "PScheduler.h"

PScheduler::PScheduler(int numThreads) {
    for(int i = 0; i < numThreads; i++){
        _threads.push_back(new PThread(NULL));
    }
}