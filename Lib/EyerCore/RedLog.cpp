#include "Red.hpp"
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <thread>

char * RedLogFile::logPath = NULL;

FILE * RedLogFile::logfp = NULL;

std::mutex RedLogFile::logMut;

int    RedLogFile::SetLogPath(char * path)
{
    int pathStrLen = strlen(path) + 1;

    if(logPath != NULL){
        free(logPath);
        logPath = NULL;
    }

    logPath = (char *)malloc(pathStrLen * sizeof(char));
    memcpy(logPath, path, pathStrLen);

    return 0;
}

FILE * RedLogFile::GetLogFile()
{
    if(logPath == NULL){
        SetLogPath((char *)"./zs.log");
    }
    if(logfp == NULL){
        logfp = fopen(logPath,"a+");
    }
    return logfp;
}

int    RedLogFile::CloseFile()
{
    if(logfp != NULL){
        fclose(logfp);
        logfp = NULL;
    }
    return 0;
}

void RedPrintf(const char * file, const char * function, int line, int level, const char * _format, ...)
{
    RedLogFile::logMut.lock();
    time_t t;
    struct tm * lt;
    time (&t);
    lt = localtime (&t);

    // std::thread::id main_thread_id = std::this_thread::get_id();
    std::thread::id main_thread_id = std::this_thread::get_id();
    if(level == LOG_LEVEL_ERROR){
        BaseRedLog ("[ ERROR ][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }
    if(level == LOG_LEVEL_INFO){
        BaseRedLog ("[ INFO  ][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }
    if(level == LOG_LEVEL_WARNING){
        BaseRedLog ("[WARNING][%d-%02d-%02d %02d:%02d:%02d][%lld]", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec, main_thread_id);
    }
    
    char * format = (char *)_format;
    // BaseRedLog("[2019-12-12 12:34:25 102][1]");
    // BaseRedLog("\033[;31m%s (%d) \033[0m",file,line);
    BaseRedLog("%s (%d) ", file, line);

    va_list ap;
    char *p;
    char *sval;
    int ival;
    double dval;
    long long llival;
    va_start(ap,_format);

    for(p=format;*p;p++)
    {
        if(*p!='%')
        {
            BaseRedLog("%c", *p);
            continue;
        }
        switch(*++p)
        {
            case 'l':
                {
                    if(*(++p) == 'l'){
                        if(*(++p) == 'd'){
                            llival = va_arg(ap,long long);
                            BaseRedLog("%lld",llival);
                            break;
                        }
                    }
                }
            case 'd':
                ival=va_arg(ap,int);
                BaseRedLog("%d",ival);
                break;
            case 'f':
                dval=va_arg(ap,double);
                BaseRedLog("%f",dval);
                break;
            case 's':
                sval=va_arg(ap,char *);
                BaseRedLog("%s",sval);
                break;
            default:
                // putchar(*p);
                BaseRedLog("%c", *p);
                break;
        }
    }
    va_end(ap);  //结束时清理工作
    RedLogFile::CloseFile();
    RedLogFile::logMut.unlock();
}
