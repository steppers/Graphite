//
// Created by Ollie on 05/11/2015.
//
#ifndef SSIMCPP_THREAD_H
#define SSIMCPP_THREAD_H

#include <thread>

using namespace std;

class SThread;

class SRunnable {
public:
    virtual void run(SThread* thread);
};

class SThread {
public:
    SThread(SRunnable* runnable){
        _runnable = runnable;
    }

    void start() {
        _thread = new thread(run, _runnable, this);
    }

    void join(){
        _thread->join();
    }

    static void sleep(long millis) {
        this_thread::sleep_for(chrono::milliseconds(millis));
    }

    static void sleepMicro(long micros) {
        this_thread::sleep_for(chrono::microseconds(micros));
    }

private:
    thread* _thread;
    SRunnable* _runnable;

    static void run(SRunnable* runnable, SThread* thread) {
        runnable->run(thread);
    }
};

#endif //SSIMCPP_THREAD_H
