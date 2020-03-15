#ifndef EYE_LIB_EYERGPUDOMINO_H
#define EYE_LIB_EYERGPUDOMINO_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerGomino;
    class EyerGominoPip;

    class EyerGomino
    {
    public:
        EyerGomino(EyerString name);
        EyerGomino(EyerGomino & gomino);
        ~EyerGomino();

        EyerGomino & operator = (EyerGomino & gomino);

        int ClearAll();

        EyerString name;

    private:

    };

    class EyerGominoPip {
    public:
        EyerGominoPip();
        ~EyerGominoPip();

        int operator << (EyerGomino * gomino);

        int ClearAll();

        int PrintStruct();

    private:
        EyerLinkedList<EyerGomino *> gomineList;
    };
}

#endif //EYE_LIB_EYERGPUDOMINO_H