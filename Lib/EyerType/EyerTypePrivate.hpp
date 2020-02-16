#ifndef	EYER_LIB_TYPE_PRIVATE_AV_H
#define	EYER_LIB_TYPE_PRIVATE_AV_H

#include <ft2build.h>
#include FT_FREETYPE_H

namespace Eyer {
    class EyerTypePrivate
    {
    public:
        FT_Library ft;
        int init = 0;
    };
}

#endif
