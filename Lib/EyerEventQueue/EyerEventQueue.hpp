//
// Created by redknot on 2020/3/26.
//

#ifndef EYE_LIB_EYEREVENTQUEUE_HPP
#define EYE_LIB_EYEREVENTQUEUE_HPP

#include "EyerCore/EyerCore.hpp"

#include <queue>

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

    private:
        std::queue<EyerEvent *> eventQueue;
    };


    class EyerEvent
    {
    public:
        EyerEvent();
        virtual ~EyerEvent();

        EyerEvent(EyerEvent & event);

        EyerEvent & operator = (EyerEvent & event);

        virtual int GetType() = 0;

    private:
        EyerString from;
        EyerString to;
    };
}

#endif //EYE_LIB_EYEREVENTQUEUE_HPP
