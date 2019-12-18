#ifndef	RED_FILE_H
#define	RED_FILE_H

#include <stdio.h>
#include <vector>

#define FILE_TYPE_FILE 1
#define FILE_TYPE_DIR 2
#define FILE_TYPE_UNKNOW 3

class RedFile;
class RedFileList;

class RedFile
{
private:
    char * path = NULL;
public:
    RedFile(char * path);
    ~RedFile();

    int FileType();
    int IsFile();
    int IsDir();
    int Exist();

    RedFileList Childen();
};

class RedFileList
{
private:
    std::vector<RedFile *> * fileList = NULL;
public:
    RedFileList();
    ~RedFileList();

    int Count();
    RedFile Get(int index);

    int PutFile(char * path);
};

#endif