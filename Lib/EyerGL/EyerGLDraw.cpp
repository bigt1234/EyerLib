#include "EyerGL.hpp"

#include "GLHeader.h"

namespace Eyer
{
    EyerGLDraw::EyerGLDraw(EyerString _vertexShaderSrc, EyerString _fragmentShaderSrc)
    {
        vertexShaderSrc = _vertexShaderSrc;
        fragmentShaderSrc = _fragmentShaderSrc;

        program = new EyerGLProgram(vertexShaderSrc, fragmentShaderSrc);
    }

    EyerGLDraw::~EyerGLDraw()
    {
        if(program != nullptr){
            delete program;
            program = nullptr;
        }
    }

    int EyerGLDraw::Init()
    {
        if(program == nullptr){
            return -1;
        }

        program->LinkProgram();

        return 0;
    }

    int EyerGLDraw::PutTexture(EyerString uniform, EyerGLTexture * texture, int textureIndex)
    {
        program->UseProgram();

        glActiveTexture(GL_TEXTURE0 + textureIndex);
        glBindTexture(GL_TEXTURE_2D, texture->GL_GetTextureId());
        program->PutUniform1i(uniform.str, GL_TEXTURE0 + textureIndex);

        return 0;
    }

    int EyerGLDraw::PutMatrix4fv(EyerString uniform, EyerMat4x4 & mat)
    {
        program->UseProgram();
        program->PutMatrix4fv(uniform, mat);
        return 0;
    }

    int EyerGLDraw::PutUniform1f(EyerString uniform, float val)
    {
        program->UseProgram();
        program->PutUniform1f(uniform, val);
        return 0;
    }

    int EyerGLDraw::SetVAO(EyerGLVAO * _vao)
    {
        vao = _vao;
        return 0;
    }

    int EyerGLDraw::Draw()
    {
        if(program == nullptr){
            return -1;
        }

        if(vao == nullptr){
            return -2;
        }

        program->UseProgram();

        vao->DrawVAO();

        glFinish();

        return 0;
    }
}