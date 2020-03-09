#include "EyerGL.hpp"

#include "GLHeader.h"
#include "EyerGLComponent.hpp"

namespace Eyer {
    EyerGLFrameBuffer::EyerGLFrameBuffer(int w, int h, EyerGLTexture * _texture)
    {
        width = w;
        height = h;

        texture = _texture;
        if(texture == nullptr){
            // 使用默认 Framebuffer
            fbo = 0;
        }
        else{
            glGenFramebuffers(1, &fbo);
            glBindFramebuffer(GL_FRAMEBUFFER, fbo);

            texture->SetDataRGBAChannel(nullptr, width, height);

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture->GL_GetTextureId(), 0);

            GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
            if (status != GL_FRAMEBUFFER_COMPLETE) {
                EyerLog("GL_FRAMEBUFFER_COMPLETE Error!!!!\n");

                if(fbo != 0){
                    glDeleteFramebuffers(1, &fbo);
                    fbo = 0;
                }
            }
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
        drawList.insertBack(draw);
        return 0;
    }

    int EyerGLFrameBuffer::AddComponent(EyerGLComponent * component)
    {
        componentList.insertBack(component);
        return 0;
    }

    int EyerGLFrameBuffer::ClearAllComponent()
    {
        componentList.clear();
        return 0;
    }

    int EyerGLFrameBuffer::Draw()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);

        glViewport(0, 0, width, height);

        for(int i=0;i<drawList.getLength();i++){
            EyerGLDraw * drawP = nullptr;
            drawList.find(i, drawP);
            if(drawP != nullptr){
                drawP->Draw();
            }
        }

        for(int i=0;i<componentList.getLength();i++){
            EyerGLComponent * componentP = nullptr;
            componentList.find(i, componentP);
            if(componentP != nullptr){
                componentP->Viewport(width, height);
                componentP->Draw();
            }
        }

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
        return 0;
    }

    int EyerGLFrameBuffer::Clear()
    {
        glBindFramebuffer(GL_FRAMEBUFFER, fbo);
        glViewport(0, 0, width, height);
        glClearColor(0.0, 0.0, 0.0, 0.0);
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
