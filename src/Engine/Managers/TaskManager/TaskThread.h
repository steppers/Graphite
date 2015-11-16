//
// Created by Ollie on 06/11/2015.
//

#ifndef SSIMCPP_TASKTHREAD_H
#define SSIMCPP_TASKTHREAD_H


#include "../../../Util/SThread.h"

class TaskManager;
class TaskThread : public SThread, SRunnable {
public:
    TaskThread(int id, TaskManager* taskManager);

    void run(SThread* thread);

    int getThreadId();
    void kill();

private:
    int _id;
    bool _running = false;

    TaskManager* _tm;
};


#endif //SSIMCPP_TASKTHREAD_H
