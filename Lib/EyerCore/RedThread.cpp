#include "Red.hpp"

#include <thread>

#include <functional>

void RedThread::detach()
{
    std::thread t(std::bind(&RedThread::run,this));
    t.detach();
}

void RedThread::join()
{
    std::thread t(std::bind(&RedThread::run,this));
    t.join();
}


int RedThread::isRunning()
{
    this->isRunMut.lock();
    int _isRun = this->isRun;
    this->isRunMut.unlock();
    return _isRun;
}

int RedThread::Stop()
{
    this->stopFlagMut.lock();
    this->stopFlag = 1;
    this->stopFlagMut.unlock();
    
    while(isRunning()){
		RedSleep(1000);
    }

    this->stopFlagMut.lock();
    this->stopFlag = 0;
    this->stopFlagMut.unlock();
    return 0;
}

void RedThread::setRunning()
{
    this->isRunMut.lock();
    this->isRun = 1;
    this->isRunMut.unlock();
}

void RedThread::setStoping()
{
    this->isRunMut.lock();
    this->isRun = 0;
    this->isRunMut.unlock();
}
