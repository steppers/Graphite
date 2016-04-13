//
// Created by steppers on 17/02/16.
//

#include "PThread.h"

PThread::PThread(PRunnable *runnable) {
    _runnable = runnable;
}

PThread::~PThread() {
    delete _thread;
}

void PThread::start() {
    _thread = new thread(run, _runnable);
}

void PThread::join() {
    _thread->join();
}