//
// Created by redknot on 2020/3/26.
//

#include "EyerEventQueue.hpp"

namespace Eyer
{
    EyerEventQueue::EyerEventQueue()
    {

    }

    EyerEventQueue::~EyerEventQueue()
    {

    }

    int EyerEventQueue::FrontTarget(EyerEvent * & event, EyerString & target)
    {
        EyerEvent * e = eventQueue.front();
        if(e->GetTo() == target){
            event = e;
            return 0;
        }

        return -1;
    }

    int EyerEventQueue::Push(EyerEvent * event)
    {
        mutex.lock();
        eventQueue.push(event);
        mutex.unlock();

        return 0;
    }

    int EyerEventQueue::Pop()
    {
        mutex.lock();
        eventQueue.pop();
        mutex.unlock();

        return 0;
    }

    int EyerEventQueue::Front(EyerEvent * & event)
    {
        mutex.lock();
        event = eventQueue.front();
        mutex.unlock();

        return 0;
    }
}