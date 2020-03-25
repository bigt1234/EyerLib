//
// Created by redknot on 2020/3/26.
//

#include "EyerEventQueue.hpp"

namespace Eyer
{
    EyerEvent::EyerEvent()
    {

    }

    EyerEvent::~EyerEvent()
    {

    }

    EyerEvent::EyerEvent(EyerEvent & event)
    {
        *this = event;
    }

    EyerEvent & EyerEvent::operator = (const EyerEvent & event)
    {
        from = event.from;
        to = event.to;

        return *this;
    }

    EyerString EyerEvent::GetFrom()
    {
        return from;
    }

    EyerString EyerEvent::GetTo()
    {
        return to;
    }

    int EyerEvent::SetFrom(const EyerString & _from)
    {
        from = _from;
        return 0;
    }

    int EyerEvent::SetTo(const EyerString & _to)
    {
        to = _to;
        return 0;
    }
}