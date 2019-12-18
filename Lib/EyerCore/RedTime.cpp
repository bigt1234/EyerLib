#include "Red.hpp"

#ifdef _MSC_VER
#include <winsock2.h>
#else
#include <sys/time.h>
#include <unistd.h>
#endif // _MSC_VER

int RedSleep(int time)
{
#ifdef _MSC_VER
	Sleep(time);
#else
	usleep(time);
#endif // _MSC_VER
	return 0;
}

red_time_t red_stamp_to_standard(int stampTime)
{
    time_t tick = (time_t)stampTime;
    struct tm tm; 
    char s[100];
    red_time_t standard;

    tm = *localtime(&tick);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
    //printf("%d: %s\n", (int)tick, s); 

    standard.tm_year = atoi(s);
    standard.tm_mon = atoi(s+5);
    standard.tm_mday = atoi(s+8);
    standard.tm_hour = atoi(s+11);
    standard.tm_min = atoi(s+14);
    standard.tm_sec = atoi(s+17);

    return standard;
}

long long red_get_system_time()
{
#ifdef _MSC_VER
	return 0L;
#else
	struct timeval start;
	gettimeofday(&start, NULL);
	long long timems = (1000 * start.tv_sec) + (start.tv_usec / 1000);

	return timems;
#endif // _MSC_VER
}

int mon_yday[2][12] =
{
    {0,31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
    {0,31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335},
};
 
int isleap(int year)
{
    return (year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0);
}

int red_mktime(red_time_t dt)
{
    int result;
    int i =0;
    result = (dt.tm_year - 1970) * 365 * 24 * 3600 + (mon_yday[isleap(dt.tm_year)][dt.tm_mon-1] + dt.tm_mday - 1) * 24 * 3600 +dt.tm_hour * 3600 + dt.tm_min * 60 + dt.tm_sec;
    for(i=1970; i < dt.tm_year; i++)
    {
        if(isleap(i))
        {
            result += 24 * 3600;
        }
    }
    return result;
}