#ifndef	EYER_LIB_REDNER_TGA_AV_H
#define	EYER_LIB_REDNER_TGA_AV_H

#include <fstream>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
#include <math.h>

namespace Eyer
{
    #pragma pack(push,1)
    struct TGA_Header {
        char idlength;
        char colormaptype;
        char datatypecode;
        short colormaporigin;
        short colormaplength;
        char colormapdepth;
        short x_origin;
        short y_origin;
        short width;
        short height;
        char  bitsperpixel;
        char  imagedescriptor;
    };
    #pragma pack(pop)

    typedef struct EyerTGAColor {
        union {
            struct {
                unsigned char b, g, r, a;
            };
            unsigned char raw[4];
            unsigned int val;
        };
        int bytespp;

        EyerTGAColor() : val(0), bytespp(1) {
        }

        EyerTGAColor(unsigned char R, unsigned char G, unsigned char B, unsigned char A) : b(B), g(G), r(R), a(A), bytespp(4) {
        }

        EyerTGAColor(int v, int bpp) : val(v), bytespp(bpp) {
        }

        EyerTGAColor(const EyerTGAColor &c) : val(c.val), bytespp(c.bytespp) {
        }

        EyerTGAColor(const unsigned char *p, int bpp) : val(0), bytespp(bpp) {
            for (int i=0; i<bpp; i++) {
                raw[i] = p[i];
            }
        }

        EyerTGAColor & operator = (const EyerTGAColor &c) {
            if (this != &c) {
                bytespp = c.bytespp;
                val = c.val;
            }
            return *this;
        }
    } EyerTGAColor;

    class EyerTgaImage
    {
    protected:
        unsigned char* data;
        int width;
        int height;
        int bytespp;

        bool   load_rle_data(std::ifstream &in);
        bool unload_rle_data(std::ofstream &out);
    public:
        enum Format {
            GRAYSCALE=1, RGB=3, RGBA=4
        };

        EyerTgaImage();
        EyerTgaImage(int w, int h, int bpp);
        EyerTgaImage(const EyerTgaImage &img);

        bool read_tga_file(const char *filename);
        bool write_tga_file(const char *filename, bool rle=true);
        bool flip_horizontally();
        bool flip_vertically();
        bool scale(int w, int h);
        
        EyerTGAColor get(int x, int y);
        bool set(int x, int y, EyerTGAColor c);

        ~EyerTgaImage();
        EyerTgaImage & operator =(const EyerTgaImage &img);

        int get_width();
        int get_height();
        int get_bytespp();
        unsigned char *buffer();
        void clear();
    };
}

#endif