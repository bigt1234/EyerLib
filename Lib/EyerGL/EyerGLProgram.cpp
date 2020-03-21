#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer
{
    EyerGLProgram::EyerGLProgram(EyerString _vertexShaderSrc, EyerString _fragmentShaderSrc)
    {
        vertexShaderSrc = _vertexShaderSrc;
        fragmentShaderSrc = _fragmentShaderSrc;
        programId = glCreateProgram();
    }

    EyerGLProgram::~EyerGLProgram()
    {
        if(programId != 0) {
            glDeleteProgram(programId);
            programId = 0;
        }
    }

    int EyerGLProgram::LinkProgram()
    {
        Eyer::EyerGLShader vertexShader(Eyer::EyerGLShaderType::VERTEX_SHADER, vertexShaderSrc);
        vertexShader.Compile();

        Eyer::EyerGLShader fragmentShader(Eyer::EyerGLShaderType::FRAGMENT_SHADER, fragmentShaderSrc);
        fragmentShader.Compile();

        glAttachShader(programId, vertexShader.GL_GetShaderId());
        glAttachShader(programId, fragmentShader.GL_GetShaderId());

        glLinkProgram(programId);

        GLint Result = GL_FALSE;
        int InfoLogLength;

        // Check the program
        glGetProgramiv(programId, GL_LINK_STATUS, &Result);
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &InfoLogLength);
        if ( InfoLogLength > 0 ){
            std::vector<char> ProgramErrorMessage(InfoLogLength+1);
            glGetProgramInfoLog(programId, InfoLogLength, NULL, &ProgramErrorMessage[0]);
            EyerLog("%s\n", &ProgramErrorMessage[0]);

            EyerLog("%s\n", vertexShaderSrc.str);
            EyerLog("%s\n", fragmentShaderSrc.str);
        }

        return 0;
    }

    int EyerGLProgram::UseProgram()
    {
        glUseProgram(programId);
        return 0;
    }

    int EyerGLProgram::PutUniform1i(EyerString key, int value)
    {
        GLuint location = glGetUniformLocation(programId, key.str);

        glUniform1i(location, value);

        return 0;
    }

    int EyerGLProgram::PutUniform1f(EyerString key, float value)
    {
        GLuint location = glGetUniformLocation(programId, key.str);

        glUniform1f(location, value);

        return 0;
    }

    int EyerGLProgram::PutMatrix4fv(EyerString key, EyerMat4x4 & _mat)
    {
        GLuint location = glGetUniformLocation(programId, key.str);

        EyerMat4x4 mat = ~_mat;
        int matLen = mat.GetMatLen();
        float * m = (float *)malloc(matLen);
        mat.GetMat(m);
        glUniformMatrix4fv(location, 1, GL_FALSE, m);
        free(m);

        return 0;
    }
}