#include "EyerGLRenderTask.hpp"
#include "EyerGLCustomComponent/EyerGLCustomComponent.hpp"

namespace Eyer
{
    YUVRenderTask::YUVRenderTask()
    {

    }

    YUVRenderTask::~YUVRenderTask()
    {

    }

    int YUVRenderTask::Render()
    {
        // yuv2text->SetWH(w, h);
        yuv2text->Draw();
        return 0;
    }

    int YUVRenderTask::Init()
    {
        if(yuv2text == nullptr){
            yuv2text = new EyerGLYUV2TextureComponent();
        }

        return 0;
    }

    int YUVRenderTask::Destory()
    {
        if(yuv2text == nullptr){
            delete yuv2text;
            yuv2text = nullptr;
        }
        return 0;
    }
}
