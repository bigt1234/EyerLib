#include "EyerGLComponent.hpp"
#include "EyerType/EyerType.hpp"
#include "Shader.hpp"

namespace Eyer
{
    EyerGLTextDraw::EyerGLTextDraw()
    {

    }

    EyerGLTextDraw::~EyerGLTextDraw()
    {

    }

    int EyerGLTextDraw::Draw()
    {
        int width = 1280;
        int height = 720;

        EyerType typeCreator("/home/redknot/Manjari-Bold.otf");
        typeCreator.Init();

        char * str = text.str;
        int strLen = strlen(str);
        for(int i=0;i<strLen;i++){
            // EyerLog(" %c \n", str[i]);
            int index = typeCreator.GenChar(str[i], 1000);
            if(index <= 0){
                continue;
            }

            EyerTypeBitmap bitmap;
            typeCreator.GetCharBitmap(index, &bitmap);

            EyerGLDraw textDraw(GL_SHADER::TEXT_VERTEX_SHADER, GL_SHADER::TEXT_FRAGMENT_SHADER);
            textDraw.Init();

            float vertex[] = {
                    1.0, 1.0, 0.0,
                    1.0, -1.0, 0.0,
                    -1.0, -1.0, 0.0,
                    -1.0, 1.0, 0.0
            };
            float coor[] = {
                    1.0, 1.0, 0.0,
                    1.0, 0.0, 0.0,
                    0.0, 0.0, 0.0,
                    0.0, 1.0, 0.0
            };
            unsigned int vertexIndex[] = {
                    0, 1, 2,
                    0, 2, 3
            };

            Eyer::EyerGLVAO vao;
            vao.AddVBO(vertex, sizeof(vertex), 0);
            vao.AddVBO(coor, sizeof(coor), 1);
            vao.SetEBO(vertexIndex, sizeof(vertexIndex));

            textDraw.SetVAO(&vao);

            Eyer::EyerGLTexture zeroTexture;
            zeroTexture.SetDataRedChannel(bitmap.data, bitmap.width, bitmap.height);

            textDraw.PutTexture("charTex", &zeroTexture);

            textDraw.Draw();
        }

        return 0;
    }

    int EyerGLTextDraw::SetText(EyerString _text)
    {
        text = _text;
        return 0;
    }

    int EyerGLTextDraw::SetSize(float size)
    {
        return 0;
    }

    int EyerGLTextDraw::SetPos(EyerVec2 pos)
    {
        return 0;
    }

    int EyerGLTextDraw::SetPos(float x, float y)
    {
        return 0;
    }

}