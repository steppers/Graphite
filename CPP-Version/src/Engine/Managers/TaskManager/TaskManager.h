//
// Created by steppers on 05/11/15.
//

#ifndef SSIMCPP_TASKMANAGER_H
#define SSIMCPP_TASKMANAGER_H

#include <vector>
#include "Task.h"
#include "../Manager.h"

using namespace std;

class TaskManager : Manager {
public:
    static TaskManager& getInstance(){
        static TaskManager tm;
        return tm;
    }

    void init();

    void submitTasks(vector<Task*>* tasks);
    void waitForTaskCompletion();
    void stop();

private:
    //Singleton initialisation----------------------------------------------------
    TaskManager(){}  //Keep the constructor and destructor private
    ~TaskManager(){}

    TaskManager(TaskManager const&) = delete;   //Prevent us from using these
    void operator=(TaskManager const&) = delete;
    //----------------------------------------------------------------------------
};


#endif //SSIMCPP_TASKMANAGER_H
