//
// Created by steppers on 04/12/15.
//

#include "Tester.h"

Thread::Thread(int id)
: SThread(&_runnable){
    _id = id;
    start();
}

int Thread::getThreadId() {
    return _id;
}

void Thread::stopThread() {
    _runnable.stop();
}

void Thread::~Thread() {
    _runnable.stop();
}