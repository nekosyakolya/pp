#pragma once
#include "Flower.h"
#include "Windows.h"

struct ThreadData
{
	ThreadData(std::vector<CFlower>* flowers, HANDLE mutex)
		: flowers(flowers),
		mutex(mutex)
	{
	}
	std::vector<CFlower>* flowers;
	HANDLE mutex;
};
