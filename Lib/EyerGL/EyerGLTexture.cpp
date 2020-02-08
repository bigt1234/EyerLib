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
}