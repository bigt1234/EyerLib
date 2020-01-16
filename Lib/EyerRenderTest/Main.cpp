#include <stdio.h>

#include <EyerRender/EyerRender.hpp>

int main()
{
    printf("Main\n");

    Eyer::EyerTGAColor white = Eyer::EyerTGAColor(255, 255, 255, 255);
    Eyer::EyerTGAColor red   = Eyer::EyerTGAColor(255, 0,   0,   255);

    Eyer::EyerTgaImage image(100, 100, Eyer::EyerTgaImage::RGB);
	image.set(52, 41, red);
	image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");

	return 0;
}