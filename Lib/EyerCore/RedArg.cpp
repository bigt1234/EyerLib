#include "RedArg.hpp"
#include <stdlib.h>
#include <string.h>

RedArg::RedArg(int argc, char * * argv)
{
    this->argc = argc;
    this->argv = (char **)malloc(argc * sizeof(char *));

    for(int i=0;i<argc;i++){
        int strLen = strlen(argv[i]) + 1;
        char * str = (char *)malloc(strLen * sizeof(char));
        memcpy(str, argv[i], strLen);

        this->argv[i] = str;        
    }
}

char * RedArg::GetArg(char * _key)
{
    for(int i=0;i<argc;i++){
        char * key = this->argv[i];
        if(strcmp(_key, key) == 0){
            if(i + 1 >= argc){
                continue;
            }
            char * targetV = this->argv[i + 1];
            char * outV = (char *)malloc((strlen(targetV) + 1) * sizeof(char));
            memcpy(outV, targetV, (strlen(targetV) + 1));
            return outV;
        }
    }
    return NULL;
}

RedArg::~RedArg()
{
    for(int i=0;i<argc;i++){
        if(this->argv[i] != NULL){
            free(this->argv[i]);
        }
    }
    free(this->argv);
    this->argv = NULL;
}

int RedArg::GetCount()
{
    return this->argc;
}