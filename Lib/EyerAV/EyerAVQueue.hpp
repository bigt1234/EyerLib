//
// Created by redknot on 2020/3/29.
//

#ifndef EYE_LIB_EYERAVQUEUE_HPP
#define EYE_LIB_EYERAVQUEUE_HPP

#include <mutex>
#include <queue>

namespace Eyer
{
    template<typename T>
    class EyerAVQueue {
    public:
        EyerAVQueue();
        ~EyerAVQueue();

        int Push(T * t);
        int Front(T ** t);
        int FrontPop(T ** t);

        int Size();
    private:
        std::mutex mut;
        std::queue<T *> queue;
    };
}



#endif //EYE_LIB_EYERAVQUEUE_HPP