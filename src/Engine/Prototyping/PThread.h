//
// Created by steppers on 17/02/16.
//

#ifndef R_ENGINE_PTHREAD_H
#define R_ENGINE_PTHREAD_H

#include "PRunnable.h"

#include <thread>

using namespace std;

class PThread {
public:
    PThread(PRunnable* runnable);
    ~PThread();

    void start();
    void join();

private:
    thread* _thread;
    PRunnable* _runnable;

    static void run(PRunnable* runnable){
        runnable->run();
    }
};


#endif //R_ENGINE_PTHREAD_H
