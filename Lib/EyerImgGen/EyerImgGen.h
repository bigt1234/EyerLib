#pragma once

namespace Eyer {

	class EyerImgGenerateSingleton {
	public:
		static EyerImgGenerateSingleton* GetInstance();

		/*
		* iW,iH,ch	图像宽,高,通道数
		* cbW,cbH	棋盘格宽,高
		* data		图像数据
		*/
		int GetCheckboard(int iW, int iH, int ch, int cbW, int cbH, unsigned char* data);
	private:
		EyerImgGenerateSingleton() {};

	public:
		static EyerImgGenerateSingleton* mInstance;
	};

	class EyerImgGenerateSingletonCG
	{
	public:
		~EyerImgGenerateSingletonCG();
	};
}