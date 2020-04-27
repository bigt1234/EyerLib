#ifndef	EYER_LIB_AV_CROP_H
#define	EYER_LIB_AV_CROP_H

namespace Eyer
{
    enum EyerAVCropType
    {
        FIT_CENTER = 0,
        FIT_XY = 1
    };

    class EyerAVCropUtil
    {
    public:
        EyerAVCropUtil();
        ~EyerAVCropUtil();

        int GetCrop(int viewW, int viewH, int imageW, int imageH, int & targetW, int & targetH,EyerAVCropType cropType = EyerAVCropType::FIT_CENTER);
    };
}

#endif