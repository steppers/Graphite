//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASKMANAGER_H
#define SSIMCPP_TASKMANAGER_H

#include <thread>
#include "../Manager.h"
#include "Task.h"
#include "TaskThread.h"
#include "../../../Util/BlockingQueue.h"
#include "../../../Util/SThread.h"

class TaskManager : Manager {
public:
    static TaskManager& getInstance(){
        static TaskManager instance;
        return instance;
    }

    void init();

    void submitTask(Task* task);
    void submitTasks(vector<Task*>* tasks);
    void killThreads();
    void waitForTasks();

    Task* takeTask();
    void notifyOfTaskCompletion();

private:
    //Singleton initialisation----------------------------------------------------
    TaskManager(); //Keep the constructor and destructor private
    ~TaskManager();

    TaskManager(TaskManager const&) = delete;   //Prevent us from using these
    void operator=(TaskManager const&) = delete;
    //----------------------------------------------------------------------------

    vector<TaskThread*> _threads;
    BlockingQueue<Task*> _tasks;

    int _totalTasks = 0;
    mutex _mutex;
    condition_variable _cond;
};

#endif //SSIMCPP_TASKMANAGER_H
