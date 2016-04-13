//
// Created by steppers on 16/02/16.
//

#ifndef _PTASK_H
#define _PTASK_H

class PTask
{
public:
    virtual void execute()=0;
    virtual signed int getDependencies(PTask**& Deps);
    virtual void onExecuted(){};

private:
    volatile signed int* _execCounter;
    volatile signed int _syncCounter;
};

#endif //_PTASK_H
