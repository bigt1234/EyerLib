#include "RedString.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * red_copy_str(char * src)
{
    if(src == NULL){
        return NULL;
    }
    int strLen = strlen(src) + 1;
    char * dist = (char *)malloc(strLen);
    memcpy(dist, src, strLen);

    return dist;
}


RedString::RedString()
{
    str = red_copy_str((char *)"");
}

RedString::RedString(const char * _str)
{

    if(_str == NULL){
        str = red_copy_str((char *)"");
        return;
    }

    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(_str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, _str, strLen);
}

RedString::RedString(char * _str)
{
    if(_str == NULL){
        str = red_copy_str((char *)"");
        return;
    }

    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(_str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, _str, strLen);
}

RedString::RedString(RedString & redstr)
{
    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(redstr.str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, redstr.str, strLen);
}

RedString::~RedString()
{
    if(str != NULL){
        free(str);
        str = NULL;
    }
}

RedString & RedString::operator = (RedString & _redstr)
{
    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(_redstr.str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, _redstr.str, strLen);

    return *this;
}

RedString & RedString::operator = (char * _str)
{
	if (_str == NULL) {
		return *this;
	}
    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(_str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, _str, strLen);

    return *this;
}

RedString & RedString::operator = (const char * _str)
{
	if (_str == NULL) {
		return *this;
	}
    if(str != NULL){
        free(str);
        str = NULL;
    }

    int strLen = strlen(_str) + 1;
    str = (char *)malloc(strLen);
    memcpy(str, _str, strLen);

    return *this;
}

RedString & RedString::operator + (char * _str)
{
    int lenA = strlen(str);
    int lenB = strlen(_str);

    char * s = (char *)malloc(lenA + lenB + 1);

    memcpy(s, str, lenA);
    memcpy(s + lenA, _str, lenB);
    s[lenA + lenB] = '\0';

    if(str != NULL){
        free(str);
        str = NULL;
    }
    str = s;

    return *this;
}

RedString & RedString::operator + (RedString & _redstr)
{
    int lenA = strlen(str);
    int lenB = strlen(_redstr.str);

    char * s = (char *)malloc(lenA + lenB + 1);

    memcpy(s, str, lenA);
    memcpy(s + lenA, _redstr.str, lenB);
    s[lenA + lenB] = '\0';

    if(str != NULL){
        free(str);
        str = NULL;
    }
    str = s;

    return *this;
}

bool RedString::operator == (RedString & _redstr)
{
    if(strcmp(this->str, _redstr.str) == 0){
        return true;
    }

    return false;
}

bool RedString::operator == (char * _str)
{
	if (strcmp(this->str, _str) == 0) {
		return true;
	}

	return false;
}

bool RedString::operator == (const char * _str)
{
	if (strcmp(this->str, _str) == 0) {
		return true;
	}

	return false;
}


bool RedString::operator > (RedString & _redstr)
{
    if(strcmp(this->str, _redstr.str) > 0){
        return true;
    }

    return false;
}

bool RedString::operator < (RedString & _redstr)
{
    if(strcmp(this->str, _redstr.str) < 0){
        return true;
    }

    return false;
}