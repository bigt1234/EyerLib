#ifndef	ZS_LIB_RED_STRING_H
#define	ZS_LIB_RED_STRING_H

#include <string.h>

char * red_copy_str(char * src);

class RedString
{
public:
    char * str = NULL;
public:
    RedString();
    RedString(char * str);
    RedString(const char * str);
    RedString(RedString & redstr);

    ~RedString();

    RedString & operator = (RedString & _redstr);
    RedString & operator = (char * _str);
    RedString & operator = (const char * _str);

    RedString & operator + (RedString & _redstr);
    RedString & operator + (char * _str);

    bool operator == (RedString & _redstr);
	bool operator == (char * _str);
	bool operator == (const char * _str);
    bool operator > (RedString & _redstr);
    bool operator < (RedString & _redstr);
};

#endif