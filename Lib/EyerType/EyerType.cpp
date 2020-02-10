#include "EyerType.hpp"
#include "EyerTypePrivate.hpp"

namespace Eyer
{
    EyerType::EyerType(EyerString _typeFile)
    {
        typeFile = _typeFile;
        impl = new EyerTypePrivate();
    }

    EyerType::~EyerType()
    {
        if(impl->init){
            FT_Done_FreeType(impl->ft);
            impl->init = 0;
        }
        if(impl != nullptr){
            delete impl;
            impl = nullptr;
        }
    }

    int EyerType::Init()
    {
        if (FT_Init_FreeType(&impl->ft)) {
            return -1;
        }
        impl->init = 1;

        return 0;
    }

    int EyerType::GenChar(char c, int pixel_height, int * width, int * height)
    {
        FT_Face face;
        if (FT_New_Face(impl->ft, typeFile.str, 0, &face))
        {
            return -2;
        }

        FT_Set_Pixel_Sizes(face, 0, pixel_height);

        if (FT_Load_Char(face, c, FT_LOAD_RENDER));

        *width = face->glyph->bitmap.width;
        *height = face->glyph->bitmap.rows;

        FT_Done_Face(face);

        return 0;
    }
}