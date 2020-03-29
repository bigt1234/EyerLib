//
// Created by redknot on 2020/3/29.
//

#include "EyerAVQueue.hpp"

namespace Eyer
{
    template<typename T>
    EyerAVQueue<T>::EyerAVQueue()
    {

    }

    template<typename T>
    EyerAVQueue<T>::~EyerAVQueue()
    {
        mut.lock();

        T * t = queue.front();
        queue.pop();
        delete t;

        mut.unlock();
    }

    template<typename T>
    int EyerAVQueue<T>::Push(T * t)
    {
        mut.lock();

        queue.push(t);

        mut.unlock();
        return 0;
    }

    template<typename T>
    int EyerAVQueue<T>::Front(T ** t)
    {
        int ret = -1;
        mut.lock();

        if(queue.size() > 0){
            *t = queue.front();
            ret = 0;
        }

        mut.unlock();
        return ret;
    }

    template<typename T>
    int EyerAVQueue<T>::FrontPop(T ** t)
    {
        int ret = -1;
        mut.lock();

        if(queue.size() > 0) {
            *t = queue.front();
            queue.pop();
            ret = 0;
        }

        mut.unlock();
        return ret;
    }

    template<typename T>
    int EyerAVQueue<T>::Size()
    {
        int size = 0;
        mut.lock();

        size = queue.size();

        mut.unlock();

        return size;
    }
}