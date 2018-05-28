#pragma once
#include "Flower.h"

struct ThreadData
{
	ThreadData(std::vector<CFlower>* flowers)
		: m_flowers(flowers)
	{
	}
	std::vector<CFlower>* m_flowers;
};
