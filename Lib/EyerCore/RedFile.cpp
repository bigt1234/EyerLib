#include "RedFile.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifdef _MSC_VER
#else
#include <dirent.h>
#endif


#include <string>

RedFile::RedFile(char * path)
{
    int pathLen = strlen(path) + 1;
    this->path = (char *)malloc(pathLen * sizeof(char));
    memcpy(this->path, path, pathLen);
}

RedFile::~RedFile()
{
    if(this->path != NULL){
        free(this->path);
        this->path = NULL;
    }
}

int RedFile::FileType()
{
#ifdef _MSC_VER
#else
	struct stat s_buf;
	stat(path, &s_buf);

	if (S_ISDIR(s_buf.st_mode))
	{
		return FILE_TYPE_DIR;
	}
	if (S_ISREG(s_buf.st_mode)) {
		return FILE_TYPE_FILE;
	}
#endif
    
    return FILE_TYPE_UNKNOW;
}

int RedFile::Exist()
{
    return 0;
}

int RedFile::IsFile()
{
    if(FileType() == FILE_TYPE_FILE){
        return 1;
    }
    return 0;
}

int RedFile::IsDir()
{
    if(FileType() == FILE_TYPE_DIR){
        return 1;
    }
    return 0;
}

RedFileList RedFile::Childen()
{
	RedFileList list;
#ifdef _MSC_VER
	return list;
#else
    if(!IsDir()){
        return list;
    }

    DIR * dp = NULL;
    dp = opendir(this->path);

    if (!dp) {
        return list; 
    }

    struct dirent * filename = NULL;
    while ((filename = readdir(dp))) 
    {
        char * fileName = filename->d_name;
        int fileNameLen = strlen(fileName);

        std::string absPath;
        absPath = std::string(this->path) + "/" + std::string(fileName);

        // char * absPath = (char *)malloc(fileNameLen + strlen(this->path) + 1 + 1);
        // memcpy(absPath, this->path, strlen(this->path));
        // absPath[strlen(this->path) + 1] = '/';
        // memcpy(absPath + strlen(this->path) + 1, fileName, fileNameLen + 1);

        list.PutFile((char *)absPath.c_str());
    }

    return list;
#endif
}