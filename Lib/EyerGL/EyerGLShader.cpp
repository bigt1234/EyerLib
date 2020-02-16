#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer{
    EyerGLShader::EyerGLShader(EyerGLShaderType _type, EyerString _src)
    {
        type = _type;
        src = _src;

        GLenum shaderType = GL_VERTEX_SHADER;
        if(type == EyerGLShaderType::VERTEX_SHADER){
            shaderType = GL_VERTEX_SHADER;
        }
        if(type == EyerGLShaderType::FRAGMENT_SHADER){
            shaderType = GL_FRAGMENT_SHADER;
        }

        shaderId = glCreateShader(shaderType);
    }

    EyerGLShader::~EyerGLShader()
    {
        if(shaderId != 0){
            glDeleteShader(shaderId);
            shaderId = 0;
        }
    }

    int EyerGLShader::Compile()
    {
        if(shaderId == 0){
            return -1;
        }

        EyerLog("Shader Src:\n %s\n", src.str);
        glShaderSource(shaderId, 1, &src.str , NULL);
        glCompileShader(shaderId);

        GLint Result = GL_FALSE;
        int InfoLogLength;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &Result);
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if ( InfoLogLength > 0 ){
            std::vector<char> ShaderErrorMessage(InfoLogLength+1);
            glGetShaderInfoLog(shaderId, InfoLogLength, NULL, &ShaderErrorMessage[0]);
            EyerLog("%s\n", &ShaderErrorMessage[0]);
        }

        return 0;
    }

    unsigned int EyerGLShader::GL_GetShaderId()
    {
        return shaderId;
    }
}
