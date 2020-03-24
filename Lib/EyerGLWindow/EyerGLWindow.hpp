#ifndef	EYER_LIB_GL_AV_WINDOWS_H
#define	EYER_LIB_GL_AV_WINDOWS_H

#include "EyerCore/EyerCore.hpp"
#include <vector>

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

        int SetBGColor(float r, float g, float b, float a);
        int Clear();

        int Open();
        int Close();
        int ShouldClose();
        int Loop();
    };
}

#endif
