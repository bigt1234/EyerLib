#ifndef	RED_IP_ADDR_H
#define	RED_IP_ADDR_H

#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#else
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>

#endif // _WIN32

class RedIPAddr
{
public:
    struct sockaddr_in * addr = NULL;
	socklen_t addrLen; 
public:
    RedIPAddr();
    RedIPAddr(struct sockaddr_in * _addr, socklen_t _addrLen);
    RedIPAddr(RedIPAddr & _addr);

    ~RedIPAddr();

    RedIPAddr & operator = (RedIPAddr & _addr);
};

#endif