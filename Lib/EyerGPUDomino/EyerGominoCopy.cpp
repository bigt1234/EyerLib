#include "EyerGPUDomino.hpp"

namespace Eyer
{
    EyerGominoCopy::EyerGominoCopy() : EyerGomino("Copy")
    {

    }

    EyerGominoCopy::~EyerGominoCopy()
    {

    }

    int EyerGominoCopy::Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height)
    {
        EyerGLFrameBuffer frameBuffer(width, height, output);

        frameBuffer.ClearAllComponent();
        frameBuffer.Clear();

        EyerCopyTextureComponent copyComponent;
        copyComponent.SetTexture(input);
        copyComponent.SetWH(width, height);

        frameBuffer.AddComponent(&copyComponent);

        frameBuffer.Draw();

        frameBuffer.ClearAllComponent();

        return 0;
    }
}