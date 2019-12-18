#include "RedByte.hpp"

RedByte::RedByte()
{

}

RedByte::RedByte(unsigned char * _data, int _dataLength)
{
    dataLength = _dataLength;
    data = (unsigned char *)malloc(_dataLength);

    memcpy(data, _data, _dataLength);
}

RedByte::RedByte(RedByte & byte)
{
    dataLength = byte.dataLength;
    data = (unsigned char *)malloc(byte.dataLength);

    memcpy(data, byte.data, byte.dataLength);
}

RedByte & RedByte::operator = (RedByte & byte)
{
    if(data != NULL){
        free(data);
        data = NULL;
    }
    
    dataLength = byte.dataLength;
    data = (unsigned char *)malloc(byte.dataLength);

    memcpy(data, byte.data, byte.dataLength);

    return *this;
}

RedByte::~RedByte()
{
    if(data != NULL){
        free(data);
        data = NULL;
    }
}

int RedByte::PushData(unsigned char * _data, int _length)
{
    unsigned char * tempData = (unsigned char *)malloc(dataLength + _length);
    int pos = 0;

    if(data != NULL){
        memcpy(tempData + pos, data, dataLength);
        pos += dataLength;
    }

    memcpy(tempData + pos, _data, _length);
    pos += _length;

    dataLength += _length;

    if(data != NULL){
        free(data);
        data = NULL;
    }

    data = tempData;

    return 0;
}

int RedByte::GetData(int _targetLength,unsigned char * * _data, int * _length)
{
    if(_targetLength <= 0){
        *_length = 0;
        return -1;
    }
    if(_targetLength > dataLength){
        *_length = 0;
        return -1;
    }

    unsigned char * outData = (unsigned char *)malloc(_targetLength);

    memcpy(outData, data, _targetLength);
    *_data = outData;
    *_length = _targetLength;

    unsigned char * tempData = (unsigned char *)malloc(dataLength - _targetLength);
    memcpy(tempData, data + _targetLength, dataLength - _targetLength);

    dataLength = dataLength - _targetLength;

    if(data != NULL){
        free(data);
        data = NULL;
    }

    data = tempData;

    return 0;
}

int RedByte::ClearAll()
{
	if (data != NULL) {
		free(data);
		data = NULL;
	}
	dataLength = 0;
	return 0;
}