#include "RedFile.hpp"

RedFileList::RedFileList()
{
    printf("Alloc List\n");
    fileList = new std::vector<RedFile *>();
}

RedFileList::~RedFileList()
{
    printf("Free List\n");
    if(fileList != NULL){
        for(int i=0;i<fileList->size();i++){
            RedFile * file = fileList->at(i);
            delete file;
        }
        delete fileList;
        fileList = NULL;
    }
}

int RedFileList::Count()
{
    return this->fileList->size();
}

RedFile RedFileList::Get(int index)
{
    RedFile file((char *)"");
    return file;
}

int RedFileList::PutFile(char * path)
{
    RedFile * file = new RedFile(path);
    fileList->push_back(file);
    return 0;
}