#include "Shader.hpp"

namespace Eyer
{
    char * GL_SHADER::TEST_VERTEX_SHADER = SHADER(
        layout (location = 0) in vec3 pos;
        void main(){
            gl_Position = vec4(pos * 1.0, 1.0);
        }
    );

    char * GL_SHADER::TEST_FRAGMENT_SHADER = SHADER(
        out vec4 color;

        void main()
        {
            color = vec4(1.0f, 0.0f, 0.0f, 1.0f);
        }
    );




    char * GL_SHADER::YUV_VIDEO_VERTEX_SHADER = SHADER(
        layout (location = 0) in vec3 pos;
        layout (location = 1) in vec3 coor;

        out vec3 outCoor;

        void main(){
            outCoor = coor;
            gl_Position = vec4(pos * 1.0, 1.0);
        }
    );

    char * GL_SHADER::YUV_VIDEO_FRAGMENT_SHADER = SHADER(
        out vec4 color;
        in vec3 outCoor;
        uniform sampler2D numberTex;

        void main()
        {
            vec2 TexCoords = vec2(outCoor.x, 1.0 - outCoor.y);
            color = texture(numberTex, TexCoords);
        }
    );

    char * GL_SHADER::TEXT_VERTEX_SHADER = SHADER(
        layout (location = 0) in vec3 pos;
        layout (location = 1) in vec3 coor;

        out vec3 outCoor;

        void main(){
            outCoor = coor;
            gl_Position = vec4(pos * 1.0, 1.0);
        }
    );

    char * GL_SHADER::TEXT_FRAGMENT_SHADER = SHADER(
        out vec4 color;
        in vec3 outCoor;
        uniform sampler2D charTex;
        void main(){
            vec2 TexCoords = vec2(outCoor.x, 1.0 - outCoor.y);
            color = texture(charTex, TexCoords);

            // color = vec4(outCoor, 1.0);
        }
    );
}