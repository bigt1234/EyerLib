#ifndef	EYER_LIB_GL_AV_H
#define	EYER_LIB_GL_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerGLWindowPrivate;

    class EyerGLWindow
    {
    private:
        EyerString title = "Eyer GL";

        int width = 0;
        int height = 0;

        EyerGLWindowPrivate * window = nullptr;
    public:
        EyerGLWindow(EyerString title, int width, int height);
        ~EyerGLWindow();

        int Open();
        int ShouldClose();
        int Loop();
    };
}

#endif