#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer {
    EyerGLFrameBuffer::EyerGLFrameBuffer()
    {

    }

    EyerGLFrameBuffer::~EyerGLFrameBuffer()
    {
        drawList.clear();
    }

    int EyerGLFrameBuffer::AddDraw(EyerGLDraw * draw)
    {
        drawList.push_back(draw);
        return 0;
    }

    int EyerGLFrameBuffer::Draw()
    {
        for(int i=0;i<drawList.size();i++){
            drawList[i]->Draw();
        }
        return 0;
    }

    int EyerGLFrameBuffer::ReadPixel(int x, int y, int width, int height, unsigned char * data)
    {
        glReadPixels(x, y, width, height, GL_RGB, GL_UNSIGNED_BYTE, data);
        return 0;
    }
}
