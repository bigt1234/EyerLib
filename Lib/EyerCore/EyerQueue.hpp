#ifndef	EYER_QUEUE_H
#define	EYER_QUEUE_H
#include "EyerLinkedEle.hpp"

namespace Eyer{
    template <typename T>
    class EyerQueue
    {
    private:
        /* data */
    public:
        EyerQueue(/* args */);
        ~EyerQueue();
        bool isEmpty() const;
        int clear();
        int enQueue(const T & data);
        int deQueue(T & data); 
    };

    template <typename T>
    EyerQueue<T>::EyerQueue(/* args */)
    {
    }

    template <typename T>
    EyerQueue<T>::~EyerQueue()
    {
    }
}


#endif
