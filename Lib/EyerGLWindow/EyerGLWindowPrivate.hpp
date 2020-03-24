#ifndef	EYER_LIB_GL_WINDOWS_PRIVATE_H
#define	EYER_LIB_GL_WINDOWS_PRIVATE_H

#include "EyerGLWindow.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Eyer
{
    class EyerGLWindowPrivate
    {
    public:
        GLFWwindow * window = NULL;
    };
}

#endif