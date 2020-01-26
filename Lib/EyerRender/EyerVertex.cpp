#include "EyerVertex.hpp"

namespace Eyer
{
    EyerVertex::EyerVertex()
    {

    }

    EyerVertex::EyerVertex(const EyerVertex & vertex)
    {
        pos = vertex.pos;
        coor = vertex.coor;

        posScale = pos;
    }

    EyerVertex::EyerVertex(float px, float py, float pz, float coorx, float coory, float coorz)
    {
        pos.SetX(px);
        pos.SetY(py);
        pos.SetZ(pz);

        coor.SetX(coorx);
        coor.SetY(coory);
        coor.SetZ(coorz);

        posScale = pos;
    }

    EyerVertex::~EyerVertex()
    {

    }

    EyerVertex & EyerVertex::operator = (const EyerVertex & vertex)
    {
        pos = vertex.pos;
        coor = vertex.coor;
        return *this;
    }

    float EyerVertex::GetPosX()
    {
        return pos.x();
    }

    float EyerVertex::GetPosY()
    {
        return pos.y();
    }

    float EyerVertex::GetPosZ()
    {
        return pos.z();
    }

    float EyerVertex::GetCoorX()
    {
        return coor.x();
    }

    float EyerVertex::GetCoorY()
    {
        return coor.y();
    }

    float EyerVertex::GetCoorZ()
    {
        return coor.z();
    }

    float EyerVertex::GetPosScaleX()
    {
        return posScale.x();
    }

    float EyerVertex::GetPosScaleY()
    {
        return posScale.y();
    }

    float EyerVertex::GetPosScaleZ()
    {
        return posScale.z();
    }
}