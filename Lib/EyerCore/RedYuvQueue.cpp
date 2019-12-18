#include "RedYuvQueue.hpp"

RedYuvQueue::RedYuvQueue()
{
    queueMut.lock();
    yuvQueue = new std::queue<RedYuv *>();
    queueMut.unlock();
}

RedYuvQueue::~RedYuvQueue()
{
    queueMut.lock();
    while(!this->yuvQueue->empty()){
        RedYuv * yuv = this->yuvQueue->front();
        this->yuvQueue->pop();
        delete yuv;
    }
    delete this->yuvQueue;
    this->yuvQueue = NULL;
    queueMut.unlock();
}

int RedYuvQueue::PutYuv(RedYuv * yuv)
{
    queueMut.lock();
    this->yuvQueue->push(yuv);
    queueMut.unlock();
    return 0;
}

RedYuv * RedYuvQueue::GetYuv()
{
    if(GetQueueCount() <= 0){
        return NULL;
    }

    queueMut.lock();
    RedYuv * yuv = this->yuvQueue->front();
    this->yuvQueue->pop();
    queueMut.unlock();

    return yuv;
}

RedYuv * RedYuvQueue::GetFirstYuv()
{
    if(GetQueueCount() <= 0){
        return NULL;
    }

    queueMut.lock();
    RedYuv * yuv = this->yuvQueue->front();
    queueMut.unlock();

    return yuv;
}

int RedYuvQueue::GetQueueCount()
{
    queueMut.lock();
    int count = this->yuvQueue->size();
    queueMut.unlock();
    return count;
}

int RedYuvQueue::ClearAllFrame()
{
    queueMut.lock();
    while(!this->yuvQueue->empty()){
        RedYuv * yuv = this->yuvQueue->front();
        this->yuvQueue->pop();
        delete yuv;
    }
    queueMut.unlock();

    return 0;
}
