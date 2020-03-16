#include "EyerGPUDomino.hpp"

namespace Eyer
{
    EyerGominoGaussianBlur::EyerGominoGaussianBlur() : EyerGomino("GaussianBlur")
    {

    }

    EyerGominoGaussianBlur::~EyerGominoGaussianBlur()
    {

    }

    int EyerGominoGaussianBlur::Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height)
    {
        EyerGLFrameBuffer frameBuffer(width, height, output);

        frameBuffer.ClearAllComponent();
        frameBuffer.Clear();

        EyerGaussianBlurComponent gaussianBlurComponent;
        gaussianBlurComponent.SetTexture(input);
        gaussianBlurComponent.SetWH(width, height);

        frameBuffer.AddComponent(&gaussianBlurComponent);

        frameBuffer.Draw();

        frameBuffer.ClearAllComponent();

        return 0;
    }
}