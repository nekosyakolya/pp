#pragma once
#include "Flower.h"
#include "Windows.h"

struct ThreadData
{
	ThreadData(std::vector<CFlower>* flowerbed, HANDLE mutex)
		: flowerbed(flowerbed),
		mutex(mutex)
	{
	}
	~ThreadData()
	{
		delete flowerbed;
		delete mutex;
	}
	std::vector<CFlower>* flowerbed;
	HANDLE mutex;
};
