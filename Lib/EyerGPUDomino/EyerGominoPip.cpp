#include "EyerGPUDomino.hpp"
#include "EyerGL/EyerGL.hpp"

namespace Eyer
{
    EyerGominoPip::EyerGominoPip()
    {

    }

    EyerGominoPip::~EyerGominoPip()
    {
        ClearAll();
    }

    int EyerGominoPip::operator << (EyerGomino * gomino)
    {
        gomineList.insertBack(gomino);
        return 0;
    }

    int EyerGominoPip::PrintStruct()
    {
        for(int i=0;i<gomineList.getLength();i++){
            EyerGomino * g = nullptr;
            gomineList.find(i, g);

            printf("=============================\n");
            printf("Gomino Layer Index: %d\n", i);
            printf("Gomino Layer name: %s\n", g->name.str);
        }

        return 0;
    }

    int EyerGominoPip::Go(EyerGLTexture * input, EyerGLTexture * output, int width, int height)
    {
        EyerLinkedList<EyerGLTexture *> tList;
        EyerGLTexture * iT = input;
        EyerGLTexture * oT = nullptr;
        for(int i=0;i<gomineList.getLength();i++){
            EyerGomino * g = nullptr;
            gomineList.find(i, g);

            if(i == gomineList.getLength() - 1){
                oT = output;
            }
            else{
                oT = new EyerGLTexture();
                tList.insertBack(oT);
            }

            // Render
            g->Go(iT, oT, width, height);

            iT = oT;
        }


        for(int i=0;i<tList.getLength();i++){
            EyerGLTexture * t = nullptr;
            tList.find(i, t);
            if(t != nullptr){
                delete t;
            }
        }
        tList.clear();

        return 0;
    }

    int EyerGominoPip::ClearAll()
    {
        /*
        for(int i=0;i<gomineList.getLength();i++){
            EyerGomino * g = nullptr;
            gomineList.find(i, g);
            if(g != nullptr){
                delete g;
            }
        }
        */
        gomineList.clear();
        return 0;
    }
}