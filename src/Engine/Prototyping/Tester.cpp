//
// Created by steppers on 04/12/15.
//

#include "Tester.h"

Thread::Thread(int id, BlockingQueue<TestTask*>* queue)
: SThread(&_runnable){
    _id = id;
    _runnable.setQueue(queue);
    start();
}

int Thread::getThreadId() {
    return _id;
}

void Thread::stopThread() {
    _runnable.stop();
}

Thread::~Thread() {
    _runnable.stop();
}

Tester::Tester() {
    for (int i = 0; i < 2; i++)
        _threads[i] = new Thread(i, &_queue);
}

Tester::~Tester() {

}

void Tester::Start() {
    for (int i = 0; i < 20; i++)
    {
        while(!_queue.empty()){}

        _queue.add(&_graphicsSys);
        _queue.add(&_loopSys);
    }

    Thread::sleep(200);
    for(Thread* t : _threads)
        _queue.add(&_terminateTask);
}