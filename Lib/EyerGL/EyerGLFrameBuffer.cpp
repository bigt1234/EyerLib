#include "EyerGL.hpp"

#include "GLHeader.h"
#include "EyerGLComponent.hpp"

namespace Eyer {
    EyerGLFrameBuffer::EyerGLFrameBuffer(int w, int h)
    {
        glGenFramebuffers(1, &fbo);
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        width = w;
        height = h;

        unsigned int framebufferColorTexture;

        glGenTextures(1, &framebufferColorTexture);
        glBindTexture(GL_TEXTURE_2D, framebufferColorTexture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, framebufferColorTexture, 0);

        GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
        if (status != GL_FRAMEBUFFER_COMPLETE) {
            EyerLog("GL_FRAMEBUFFER_COMPLETE Error!!!!\n");
        }
    }

    EyerGLFrameBuffer::~EyerGLFrameBuffer()
    {
        if(fbo != 0){
            glDeleteFramebuffers(1, &fbo);
            fbo = 0;
        }
        drawList.clear();
        componentList.clear();
    }

    int EyerGLFrameBuffer::AddDraw(EyerGLDraw * draw)
    {
        drawList.push_back(draw);
        return 0;
    }

    int EyerGLFrameBuffer::AddComponent(EyerGLComponent * component)
    {
        componentList.push_back(component);
        return 0;
    }

    int EyerGLFrameBuffer::Draw()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        for(int i=0;i<drawList.size();i++){
            drawList[i]->Draw();
        }

        for(int i=0;i<componentList.size();i++){
            componentList[i]->Draw();
        }
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return 0;
    }

    int EyerGLFrameBuffer::Clear()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glViewport(0, 0, width, height);
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return 0;
    }

    int EyerGLFrameBuffer::ReadPixel(int x, int y, int width, int height, unsigned char * data)
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glReadPixels(x, y, width, height, GL_BGR, GL_UNSIGNED_BYTE, data);
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return 0;
    }
}
