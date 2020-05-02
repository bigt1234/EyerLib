#ifndef	EYER_LIB_GL_RENDER_TASK_H
#define	EYER_LIB_GL_RENDER_TASK_H

#include "EyerCore/EyerCore.hpp"
#include "EyerGLCustomComponent/EyerGLCustomComponent.hpp"

namespace Eyer
{
    class EyerGLRenderTask
    {
    public:
        EyerGLRenderTask();
        virtual ~EyerGLRenderTask();

        int SetWH(int w, int h);

        // 外部只能复写，不能调用
        virtual int Render() = 0;
        virtual int Init() = 0;
        virtual int Destory() = 0;

    public:
        int w = 0;
        int h = 0;
    };

    class EyerGLRenderTaskQueue
    {
    public:
        EyerGLRenderTaskQueue();
        ~EyerGLRenderTaskQueue();

        int GetSize();

        int PushRendTask(EyerGLRenderTask * renderTask);
        int PopAndRender(int w, int h);
    private:
        EyerLockQueue<EyerGLRenderTask> taskQueue;
    };


    class JuliaRenderTask : public EyerGLRenderTask
    {
    public:
        JuliaRenderTask();
        ~JuliaRenderTask();

        virtual int Render();
        virtual int Init();
        virtual int Destory();

    private:
        EyerGLJulia * julia = nullptr;
    };
}


#endif