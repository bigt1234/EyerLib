#include "EyerCrop.hpp"

namespace Eyer
{
    EyerAVCrop::EyerAVCrop(int _viewW, int _viewH, int _imageW, int _imageH)
    {
        viewW = _viewW;
        viewH = _viewH;
        imageW = _imageW;
        imageH = _imageH;
    }

    EyerAVCrop::~EyerAVCrop()
    {

    }

    int EyerAVCrop::GetCropW()
    {
        return cropW;
    }

    int EyerAVCrop::GetCropH()
    {
        return cropH;
    }

    int EyerAVCrop::Crop(EyerAVCropType cropType)
    {
        EyerAVCropUtil cropUtil;
        return cropUtil.GetCrop(viewW, viewH, imageW, imageH, cropW, cropH, cropType);
    }
}