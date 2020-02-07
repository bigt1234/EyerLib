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
        int Close();
        int ShouldClose();
        int Loop();
    };


    class EyerGLCMD
    {
    public:
    };

    enum EyerGLShaderType
    {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };

    class EyerGLShader;
    class EyerGLProgram;
    class EyerGLVAO;

    class EyerGLShader : EyerGLCMD
    {
    private:
        EyerGLShaderType type = EyerGLShaderType::VERTEX_SHADER;
        EyerString src;
        unsigned int shaderId = 0;
    public:
        EyerGLShader(EyerGLShaderType type, EyerString src);
        ~EyerGLShader();

        int Compile();

        unsigned int GL_GetShaderId();
    };

    class EyerGLProgram : EyerGLCMD
    {
    private:
        EyerString vertexShaderSrc;
        EyerString fragmentShaderSrc;

        unsigned int programId = 0;
    public:
        EyerGLProgram(EyerString vertexShaderSrc, EyerString fragmentShaderSrc);
        ~EyerGLProgram();
        int LinkProgram();
    };

    class EyerGLVAO : EyerGLCMD
    {
    private:
        unsigned int VAOId = 0;
        unsigned int EBOId = 0;
    public:
        EyerGLVAO();
        ~EyerGLVAO();

        int SetEBO(unsigned int * EBOdata, int bufferSize);
    };
}

#endif