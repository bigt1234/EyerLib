#include "RedIPAddr.hpp"

#include <stdlib.h>

RedIPAddr::RedIPAddr()
{
    addrLen = sizeof(struct sockaddr_in);
    addr = (struct sockaddr_in *)malloc(addrLen);
}

RedIPAddr::~RedIPAddr()
{
    if(addr != NULL){
        free(addr);
        addr = NULL;
    }
}

RedIPAddr::RedIPAddr(struct sockaddr_in * _addr, socklen_t _addrLen)
{
    if(addr != NULL){
        free(addr);
        addr = NULL;
    }

    addrLen = _addrLen;
    addr = (struct sockaddr_in *)malloc(addrLen);

    memcpy(addr, _addr, addrLen);
}

RedIPAddr::RedIPAddr(RedIPAddr & _addr)
{
    addrLen = sizeof(struct sockaddr_in);
    addr = (struct sockaddr_in *)malloc(addrLen);

    memcpy(addr, _addr.addr, addrLen);
}

RedIPAddr & RedIPAddr::operator = (RedIPAddr & _addr)
{
    if(addr != NULL){
        free(addr);
        addr = NULL;
    }

    addrLen = _addr.addrLen;
    addr = (struct sockaddr_in *)malloc(addrLen);

    memcpy(addr, _addr.addr, addrLen);

    return *this;
}