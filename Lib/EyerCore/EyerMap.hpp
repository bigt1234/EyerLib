#ifndef	EYER_MAP_H
#define	EYER_MAP_H
#include "EyerMapEle.hpp"

namespace Eyer {

	template<typename K, typename V>
	class EyerMap
	{	
	public:
		EyerMap();
		~EyerMap();
		int insert(K & key, V & value, EyerMapEle<K,V> * ele = nullptr);
		int circleEle(EyerMapEle<K, V>* ele);
		int getSize();
		EyerMapEle<K, V>* head;

	private:
		int size = 0;

	};

	template<typename K, typename V>
	int EyerMap<K, V>::insert(K& key, V& value, EyerMapEle<K, V> * ele)
	{
		if (size == 0) {
			head->key = key;
			head->value = value;
			size++;
			return 0;
		}

		if (nullptr == ele) {
			ele = new EyerMapEle<K, V>(key, value);
			size++;
		}else if (key > ele->key) {
			insert(key, value, ele->leftMapEle);
		}else if (key < ele->key) {
			insert(key, value, ele->rightMapEle);
		}
	}


	template<typename K, typename V>
	EyerMap<K, V>::EyerMap()
	{
		head = new EyerMapEle<K, V>(0, 0);
	}

	template<typename K, typename V>
	EyerMap<K, V>::~EyerMap()
	{
		
	}

	template<typename K, typename V>
	int EyerMap<K, V>::getSize()
	{
		return size;
	}

	template<typename K, typename V>
	int EyerMap<K, V>::circleEle(EyerMapEle<K, V>* ele)
	{
		printf("in circleEle \n");
		if (nullptr != ele) {
			printf("key:%d,vaule:%d \n", ele->key, ele->value);
			printf("ele->leftMapEle: key,%d; key");
			circleEle(ele->leftMapEle);
			circleEle(ele->rightMapEle);
		}
		return 0;
	}
}

#endif