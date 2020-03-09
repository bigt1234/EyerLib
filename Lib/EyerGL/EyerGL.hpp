#ifndef	EYER_LIB_GL_AV_H
#define	EYER_LIB_GL_AV_H

#include "EyerCore/EyerCore.hpp"
#include "EyerType/EyerType.hpp"
#include <vector>

namespace Eyer
{
    class EyerGLWindow;
    class EyerGLWindowPrivate;
    class EyerGLCMD;

    class EyerGLComponent;
    class EyerGLTextDraw;
    class EyerGLSingleTextureDraw;
    class EyerGLFrameDraw;

    class EyerGLShader;
    class EyerGLProgram;
    class EyerGLVAO;
    class EyerGLTexture;

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


    class EyerGLCMD
    {
    public:
        virtual ~EyerGLCMD()
        {

        }
    };

    enum EyerGLShaderType
    {
        VERTEX_SHADER,
        FRAGMENT_SHADER
    };

    class EyerGLShader : public EyerGLCMD
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

    class EyerGLProgram : public EyerGLCMD
    {
    private:
        EyerString vertexShaderSrc;
        EyerString fragmentShaderSrc;

        unsigned int programId = 0;
    public:
        EyerGLProgram(EyerString vertexShaderSrc, EyerString fragmentShaderSrc);
        ~EyerGLProgram();
        int LinkProgram();
        int UseProgram();

        int PutUniform1i(EyerString key, int value);
        int PutMatrix4fv(EyerString key, EyerMat4x4 & mat);
        int PutUniform1f(EyerString key, float value);
    };

    class EyerGLVAO : public EyerGLCMD
    {
    private:
        unsigned int VAOId = 0;
        unsigned int EBOId = 0;
        std::vector<unsigned int> vboList;

        int DrawTime = 0;
    public:
        EyerGLVAO();
        ~EyerGLVAO();

        int SetEBO(unsigned int * EBOdata, int bufferSize);
        int AddVBO(float * VBOdata, int bufferSize, int layout, int size = 3, unsigned int stride = 0);

        int DrawVAO();
    };

    class EyerGLDrawTexture
    {
    public:
        EyerString uniformName;
        EyerGLTexture * texture = nullptr;
    };

    class EyerGLDraw : public EyerGLCMD
    {
    private:
        EyerString vertexShaderSrc;
        EyerString fragmentShaderSrc;

        EyerGLProgram * program = nullptr;
        EyerGLVAO * vao = nullptr;

    public:
        EyerGLDraw(EyerString vertexShaderSrc, EyerString fragmentShaderSrc);
        ~EyerGLDraw();

        int Init();

        int SetVAO(EyerGLVAO * vao);
        int PutTexture(EyerString uniform, EyerGLTexture * texture, int textureIndex = 0);
        int PutMatrix4fv(EyerString uniform, EyerMat4x4 & mat);
        int PutUniform1f(EyerString uniform, float val);

        int Draw();
    };

    class EyerGLTexture : public EyerGLCMD
    {
    private:
        unsigned int textureId = 0;
    public:
        EyerGLTexture();
        ~EyerGLTexture();

        unsigned int GL_GetTextureId();

        int SetDataRedChannel(unsigned char * data,int width,int height);
        int SetDataRGBAChannel(unsigned char * data,int width,int height);
    };

    class EyerGLFrameBuffer : public EyerGLCMD
    {
    private:
        EyerLinkedList<EyerGLDraw *> drawList;
        EyerLinkedList<EyerGLComponent *> componentList;

        unsigned int fbo = 0;

        int width = 0;
        int height = 0;

        EyerGLTexture * texture = nullptr;
    public:
        EyerGLFrameBuffer(int w, int h, EyerGLTexture * texture = nullptr);
        ~EyerGLFrameBuffer();

        int AddDraw(EyerGLDraw * draw);
        int AddComponent(EyerGLComponent * component);
        int ClearAllComponent();

        int Clear();

        int Draw();

        int ReadPixel(int x, int y, int width, int height, unsigned char * data);
    };


    class EyerGLComponent
    {
    public:
        int width = 0;
        int height = 0;
    public:
        virtual ~EyerGLComponent();

        virtual int Draw() = 0;

        int Viewport(int w, int h);
    };

    class EyerGLCacheTexture;

    class EyerGLTextDraw : public EyerGLComponent
    {
    public:
        EyerGLTextDraw(EyerString _typeFilePath);
        ~EyerGLTextDraw();

        int GetTextWidth();

        int SetText(EyerString text);

        int SetSize(float size);
        int SetPos(EyerVec2 & pos);
        int SetPos(float x, float y);

        int SetColor(float r, float g, float b);

        virtual int Draw();

    private:


        EyerString typeFilePath;

        EyerString text;
        EyerGLDraw * pointDraw = nullptr;
        EyerGLVAO * pointVao = nullptr;
        EyerType * typeCreator = nullptr;
        EyerGLDraw * textDraw = nullptr;
        EyerGLVAO * vao = nullptr;

        std::map<wchar_t, EyerGLCacheTexture *> textureCache;

        EyerVec2 pos;

        int size = 100;

        float r = 0.0f;
        float g = 0.0f;
        float b = 0.0f;
    };

    class EyerGLSingleTextureDraw : public EyerGLComponent
    {
    public:
        EyerGLSingleTextureDraw();
        ~EyerGLSingleTextureDraw();

        int SetTexture(EyerGLTexture * texture);

        virtual int Draw();

    private:
        EyerGLTexture * texture = nullptr;

        EyerGLVAO * vao = nullptr;
        EyerGLDraw * textureDraw = nullptr;
    };

    class EyerGLFrameDraw : public EyerGLComponent
    {
    public:
        EyerGLFrameDraw();
        ~EyerGLFrameDraw();

        int SetVideoWH(int w, int h);

        int SetYTexture(EyerGLTexture * yTex);
        int SetUTexture(EyerGLTexture * uTex);
        int SetVTexture(EyerGLTexture * vTex);

        int SetMVP(EyerMat4x4 & mvp);

        virtual int Draw();

    private:
        EyerGLVAO * vao = nullptr;
        EyerGLDraw * textureDraw = nullptr;

        EyerGLTexture * yTex = nullptr;
        EyerGLTexture * uTex = nullptr;
        EyerGLTexture * vTex = nullptr;

        EyerMat4x4 * mvp = nullptr;

        int videoW = 0;
        int videoH = 0;
    };

    class EyerGLCacheTexture
    {
    public:
        Eyer::EyerGLTexture * texture = nullptr;
        int width = 0;
        int height = 0;
        int bearingY = 0;
        int bearingX = 0;
        int advance = 0;
    };
}

#endif
