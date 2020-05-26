#include "EyerImgGen.h"
#include <mutex>

namespace Eyer
{
	std::mutex gEyerImgGenerateMtx;
	EyerImgGenerateSingleton* EyerImgGenerateSingleton::mInstance = nullptr;

	EyerImgGenerateSingleton* EyerImgGenerateSingleton::GetInstance()
	{
		if (mInstance == nullptr)
		{
			std::unique_lock<std::mutex> ul(gEyerImgGenerateMtx);
			if (mInstance == nullptr)
			{
				mInstance = new EyerImgGenerateSingleton();
				static EyerImgGenerateSingletonCG cg;
			}
		}

		return mInstance;
	}

	EyerImgGenerateSingletonCG::~EyerImgGenerateSingletonCG()
	{
		if (EyerImgGenerateSingleton::mInstance)
		{
			delete EyerImgGenerateSingleton::mInstance;
			EyerImgGenerateSingleton::mInstance = nullptr;
		}
	}

	int EyerImgGenerateSingleton::GetCheckboard(int iW, int iH, int ch, int cbW, int cbH, unsigned char* data)
	{
		for (int i = 0; i < iH; i++)
		{
			int m = (i / cbH) % 2;
			for (int j = 0; j < iW; j++)
			{
				int n = (j / cbW) % 2;
				bool black = (m == 0 && n == 0) || (m == 1 && n == 1);
				int color = (black ? 0 : 255);
				data[i * iW * ch + j * ch + 0] = color;
				data[i * iW * ch + j * ch + 1] = color;
				data[i * iW * ch + j * ch + 2] = color;
				if (ch == 4)
					data[i * iW * ch + j * ch + 3] = 255;
			}
		}
		return 0;
	}
}