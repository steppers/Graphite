//
// Created by Ollie on 05/11/2015.
//

#ifndef SSIMCPP_BLOCKINGQUEUE_H
#define SSIMCPP_BLOCKINGQUEUE_H

#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

template <typename T>
class BlockingQueue
{
public:
    void add(T val)
    {
        {unique_lock<mutex> lock(_mutex);   //Syncronize this function
        _queue.push(val);}            //Push an element
        _condition.notify_one();
    }

    T take()
    {
        unique_lock<mutex> lock(_mutex);    //Syncronize this function
        while(_queue.empty())
            _condition.wait(lock);          //Wait for an element
        T r = _queue.front();
        _queue.pop();
        return r;
    }

    bool empty()
    {
        return _queue.empty();
    }
private:
    mutex _mutex;
    condition_variable _condition;
    queue<T> _queue;
};

#endif //SSIMCPP_BLOCKINGQUEUE_H
