#ifndef	ZS_LIB_RED_YUV_QUEUE_H
#define	ZS_LIB_RED_YUV_QUEUE_H

#include "RedYuv.hpp"
#include <queue>
#include <mutex>

class RedYuvQueue
{
private:
    std::queue<RedYuv *> * yuvQueue = NULL;
    std::mutex queueMut;
public:
    RedYuvQueue();
    ~RedYuvQueue();

    int PutYuv(RedYuv * yuv);
    RedYuv * GetYuv();
    RedYuv * GetFirstYuv();
    int GetQueueCount();
    int ClearAllFrame();
};

#endif
