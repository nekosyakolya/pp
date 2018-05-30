#pragma once
#include "Flower.h"

class CGardener
{
public:
	CGardener();
	void WaterFlower(CFlower& flower);
	~CGardener();

private:
	size_t m_id;
	static size_t m_gardenerId;
};
