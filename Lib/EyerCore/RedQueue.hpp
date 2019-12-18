#ifndef	RED_QUEUE_H
#define	RED_QUEUE_H

#include <queue>
#include <mutex>

template <typename T> 
class RedQueue
{
private:
    std::queue<T> queue;
    std::mutex queueMut;
public: 
    RedQueue();
    ~RedQueue();

    int Push(const T & t);
    int Get(T & t);
    int Size();
};

template <typename T>
RedQueue<T>::RedQueue()
{
    
}

template<typename T>
RedQueue<T>::~RedQueue()
{
}

template<typename T>
int RedQueue<T>::Push(const T & t)
{
    queueMut.lock();
    queue.push(t);
    queueMut.unlock();
    return 0;
}

template<typename T>
int RedQueue<T>::Get(T & t)
{
    int ret = -1;
    queueMut.lock();
    if(queue.size() > 0){
        ret = 0;
        t = queue.front();
        queue.pop();    
    }
    queueMut.unlock();

    return ret;
}

template<typename T>
int RedQueue<T>::Size()
{
    int size = 0;
    queueMut.lock();
    size = queue.size();
    queueMut.unlock();

    return size;
}

#endif
