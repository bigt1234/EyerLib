//
// Created by redknot on 2020/3/26.
//

#ifndef EYE_LIB_EYEREVENTQUEUE_HPP
#define EYE_LIB_EYEREVENTQUEUE_HPP

#include "EyerCore/EyerCore.hpp"

#include <queue>
#include <mutex>

namespace Eyer
{
    class EyerEventQueue;
    class EyerEvent;

    class EyerEventQueue
    {
    public:
        EyerEventQueue();
        ~EyerEventQueue();

        int Push(EyerEvent * event);
        int Pop();

        int Front(EyerEvent * & event);

        int FrontTarget(EyerEvent * & event, const EyerString & target);
        int FrontTargetAndPop(EyerEvent * & event, const EyerString & target);

    private:
        std::queue<EyerEvent *> eventQueue;
        std::mutex mutex;
    };


    class EyerEvent
    {
    public:
        EyerEvent();
        virtual ~EyerEvent();

        EyerEvent(EyerEvent & event);

        EyerEvent & operator = (const EyerEvent & event);

        virtual int GetType() = 0;

        EyerString GetFrom();
        EyerString GetTo();

        int SetFrom(const EyerString & from);
        int SetTo(const EyerString & to);

    private:
        EyerString from;
        EyerString to;
    };
}

#endif //EYE_LIB_EYEREVENTQUEUE_HPP
