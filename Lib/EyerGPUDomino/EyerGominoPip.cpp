#include "EyerGPUDomino.hpp"

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