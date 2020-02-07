#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer
{
    EyerGLVAO::EyerGLVAO()
    {
        glGenVertexArrays(1, &VAOId);
    }

    EyerGLVAO::~EyerGLVAO()
    {
        if(VAOId != 0){
            glDeleteVertexArrays(1, &VAOId);
            VAOId = 0;
        }
    }

    int EyerGLVAO::SetEBO(unsigned int * EBOdata, int bufferSize)
    {
        if(VAOId == 0){
            return -1;
        }

        glBindVertexArray(VAOId);

        glGenBuffers(1,&EBOId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, bufferSize, EBOdata, GL_STATIC_DRAW);

        glBindVertexArray(0);
        
        return 0;
    }
}