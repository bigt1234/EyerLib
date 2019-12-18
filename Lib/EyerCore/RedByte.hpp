#ifndef	RED_BYTE_H
#define	RED_BYTE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

class RedByte
{
public:
    unsigned char * data = NULL;
    int dataLength = 0;
public:
    RedByte();
    RedByte(unsigned char * _data, int _dataLength);
    RedByte(RedByte & byte);
    ~RedByte();

    RedByte & operator = (RedByte & byte);

    int PushData(unsigned char * _data, int _length);
    int GetData(int _targetLength,unsigned char * * _data, int * _length);
	int ClearAll();
};

#endif