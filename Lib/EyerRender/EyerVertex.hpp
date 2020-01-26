#ifndef	EYER_LIB_REDNER_VERTEX_AV_H
#define	EYER_LIB_REDNER_VERTEX_AV_H

#include "EyerCore/EyerCore.hpp"

namespace Eyer
{
    class EyerVertex
    {
    private:
        EyerVec3 pos;
        EyerVec3 coor;

        EyerVec3 posScale;
    public:
        EyerVertex();
        EyerVertex(const EyerVertex & vertex);
        EyerVertex(float px, float py, float pz, float coorx, float coory, float coorz);
        ~EyerVertex();

        EyerVertex & operator = (const EyerVertex & vertex);

        float GetPosX();
        float GetPosY();
        float GetPosZ();

        float GetPosScaleX();
        float GetPosScaleY();
        float GetPosScaleZ();

        float GetCoorX();
        float GetCoorY();
        float GetCoorZ();
    };
}

#endif