#ifndef	ZS_LIB_LOG_H
#define	ZS_LIB_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <mutex>

class RedLogFile{
private:
    static FILE * logfp;
    static char * logPath;

public:
    static std::mutex logMut;
    static int    SetLogPath(char * path);
    static FILE * GetLogFile();
    static int    CloseFile();
};

#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_INFO 2
#define LOG_LEVEL_WARNING 3

#define RedLog(format, ...) RedPrintf(__FILE__, __FUNCTION__ ,__LINE__,LOG_LEVEL_INFO ,format, ##__VA_ARGS__)
// #define BaseRedLog(format, ...) fprintf(RedLogFile::GetLogFile(), format, ##__VA_ARGS__)
#define BaseRedLog(format, ...) printf(format, ##__VA_ARGS__)

void RedPrintf(const char * file, const char * function, int line, int level, const char * _format, ...);

#endif