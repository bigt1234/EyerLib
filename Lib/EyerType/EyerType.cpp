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
        std::map<int, EyerTypeBitmap *>::iterator it;
        for(it=bitmapCache.begin();it!=bitmapCache.end();++it){
            EyerTypeBitmap * bitmap = it->second;
            delete bitmap;
        }
        bitmapCache.clear();

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


    int EyerType::GenChar(wchar_t c, int pixel_height)
    {
        FT_Face face;
        if (FT_New_Face(impl->ft, typeFile.str, 0, &face))
        {
            EyerLog("FT_New_Face Fail\n");
            return -2;
        }

        FT_Set_Pixel_Sizes(face, 0, pixel_height);

        if (FT_Load_Char(face, c, FT_LOAD_RENDER));

        unsigned int bitmapDataLen = face->glyph->bitmap.width * face->glyph->bitmap.rows;

        EyerTypeBitmap * b = new EyerTypeBitmap(face->glyph->bitmap.width, face->glyph->bitmap.rows, face->glyph->bitmap_left, face->glyph->bitmap_top, face->glyph->advance.x, face->glyph->bitmap.buffer, bitmapDataLen);

        bitmapCache.insert(std::pair<int, EyerTypeBitmap *>(indexIndex, b));

        FT_Done_Face(face);

        return indexIndex;
    }

    int EyerType::GetCharBitmap(int index, EyerTypeBitmap * _bitmap)
    {
        std::map<int, EyerTypeBitmap *>::iterator it = bitmapCache.find(index);
        if(it == bitmapCache.end()) {
            return -1;
        }
        else {
            EyerTypeBitmap * bitmap = it->second;
            *_bitmap = *bitmap;
            delete bitmap;
            bitmapCache.erase(index);
        }

        return 0;
    }
}