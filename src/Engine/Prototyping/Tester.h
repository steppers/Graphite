//
// Created by steppers on 04/12/15.
//

#include "PRunnable.h"

#ifndef R_ENGINE_TESTER_H
#define R_ENGINE_TESTER_H

#include <iostream>
#include "PThread.h"

using namespace std;

class Tester {
public:
    void start();
};

class R1 : public PRunnable {
public:
    void run();
};

//
//#include "../../Util/SThread.h"
//#include "../../Util/BlockingQueue.h"
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//class Thread;
//
//template <typename T>
//class SharedAtom {
//public:
//    SharedAtom(T* val) {
//        _val = val;
//    }
//    T* getCopy() {
//        T* t = new T(*_val);
//        _values.push_back(t);
//        return t;
//    }
//    void sync(T* t)
//    {
//        for(T* tmp : _values)
//            *tmp = *t;
//        *_val = *t;
//    }
//private:
//    T* _val;
//    vector<T*> _values;
//};
//
//class TestTask {
//public:
//    virtual void execute(Thread* taskThread) = 0;
//};
//
//class Thread : public SThread {
//public:
//    Thread(int threadId, BlockingQueue<TestTask*>* queue);
//    ~Thread();
//
//    int getThreadId();
//    void stopThread();
//
//private:
//    int _id;
//
//    class TaskRunnable : public SRunnable {
//    public:
//        void run(SThread* thread) {
//            while(_running) {
//                TestTask* task = _queue->take();
//                task->execute((Thread*)thread);
//            }
//        }
//        void stop(){ _running = false; }
//        void setQueue(BlockingQueue<TestTask*>* queue) { _queue = queue; }
//    private:
//        bool _running = true;
//        BlockingQueue<TestTask*>* _queue;
//    };
//
//    TaskRunnable _runnable;
//};
//
//class TerminateTask : public TestTask {
//public:
//    void execute(Thread* taskThread) {
//        taskThread->stopThread();
//    }
//};
//
//class GraphicsSys : public TestTask {
//public:
//    int* _life;
//    GraphicsSys(SharedAtom<int>* life) {
//        _life = life->getCopy();
//    }
//    void execute(Thread* taskThread){
//        cout << "Life:" << *_life << " [Graphics]" << endl;
//    }
//};
//
//class LoopSys : public TestTask {
//public:
//    int* _life;
//    LoopSys(SharedAtom<int>* life) {
//        _life = life->getCopy();
//    }
//    void execute(Thread* taskThread) {
//        cout << "Life:" << (*_life)++ << " [Game Loop]" << endl;
//    }
//};
//
//class Tester {
//public:
//    Tester();
//    ~Tester();
//
//    void Start();
//
//private:
//    Thread* _threads[2];
//    BlockingQueue<TestTask*> _queue;
//
//    SharedAtom<int>* _sharedLife;
//
//    GraphicsSys* _graphicsSys;
//    LoopSys* _loopSys;
//
//    TerminateTask _terminateTask;
//
//    void terminateThreads();
//};
//
////template <typename T>
////class Change {
////    Change(SharedAtom<T>* shared, T* value){
////        _shared = shared;
////        _val = value;
////    }
////    SharedAtom<T>* _shared;
////    T* _val;
////};
////
////class ChangeManager {
////public:
////    ChangeManager(int threads) {
////        _changeQueues = new vector<Change*>[threads];
//////        for(int i = 0; i < threads; i++) {
//////            _changeQueues[i] = new vector<Change*>;
//////        }
////    }
////    void submitChange(Change* c, int threadId) {
////        _changeQueues[threadId].push_back(c);
////    }
////
////    void distributeChanges() {
////        for(int i = 0; i < 2; i++) {
////            for(Change* c : _changeQueues[i]) {
////                c->_shared->sync(c->_val);
////            }
////        }
////    }
////
////private:
////    vector<Change*>* _changeQueues;
////};
//
#endif //R_ENGINE_TESTER_H
