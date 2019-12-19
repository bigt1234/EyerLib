#ifndef	ZS_LIB_H
#define	ZS_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <mutex>
#include <atomic>
#include "RedLog.hpp"
#include "RedFile.hpp"
#include "RedArg.hpp"
#include "RedYuv.hpp"
#include "RedString.hpp"
#include "RedYuvQueue.hpp"
#include "RedQueue.hpp"
#include "RedMap.hpp"
#include "RedLruMap.hpp"
#include "RedByte.hpp"
#include "RedIPAddr.hpp"

#ifdef	__cplusplus
extern	"C" {
#endif

int RedSleep(int time);

long long red_get_system_time();

typedef struct red_time_t {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
}red_time_t;
 
int isleap(int year);
int red_mktime(red_time_t dt);

red_time_t red_stamp_to_standard(int stampTime);

#ifdef	__cplusplus
}
#endif


class RedThread;

class RedThread
{
private:
    std::mutex isRunMut;
    std::atomic_int isRun {0};
public:
    std::mutex stopFlagMut;
    std::atomic_int stopFlag {0};
public:
    void setRunning();
    void setStoping();
    int Stop();

    virtual void run() = 0;

    int isRunning();
    void detach();
    void join();
};


#endif