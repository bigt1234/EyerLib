#pragma once

namespace Eyer {

	class EyerImgGenerateSingleton {
	public:
		static EyerImgGenerateSingleton* GetInstance();

		/*
		* iW,iH,ch	ͼ���,��,ͨ����
		* cbW,cbH	���̸��,��
		* data		ͼ������
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