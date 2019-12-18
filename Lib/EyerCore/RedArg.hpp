#ifndef	RED_ARG_H
#define	RED_ARG_H

#include <stdio.h>

class RedArg
{
private:
    int argc = 0;
    char * * argv = NULL;
public:
    RedArg(int argc, char * * argv);
    ~RedArg();

    char * GetArg(char * key);
    int GetCount();
};

#endif