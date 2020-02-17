#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer
{
    EyerGLTexture::EyerGLTexture()
    {
        glGenTextures(1, &textureId);

        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    EyerGLTexture::~EyerGLTexture()
    {
        if(textureId != 0){
            glDeleteTextures(1, &textureId);
            textureId = 0;
        }
    }

    unsigned int EyerGLTexture::GL_GetTextureId()
    {
        return textureId;
    }

    int EyerGLTexture::SetDataRedChannel(unsigned char * data,int width,int height)
    {

        glBindTexture(GL_TEXTURE_2D, textureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        
        return 0;
    }

    int EyerGLTexture::SetDataRGBAChannel(unsigned char * data,int width,int height)
    {
        glBindTexture(GL_TEXTURE_2D, textureId);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glBindTexture(GL_TEXTURE_2D, 0);
        return 0;
    }
}
