#include "stdafx.h"
#include "Gardener.h"

size_t CGardener::m_gardenerId = 0;

CGardener::CGardener()
	: m_id(++m_gardenerId)
{
}

void CGardener::WaterFlower(CFlower& flower)
{
	int idGardener = static_cast<int>(m_id);
	int idFlower = static_cast<int>(flower.GetId());

	std::printf("садовод #%d пришел к  цветочку #%d\n", idGardener, idFlower);
	if (flower.IsFlaccidFlower())
	{
		std::printf("садовод #%d поливает цветочек #%d\n", idGardener, idFlower);
		flower.SetState(FlowerState::FLOWERING);
		std::printf("цветок #%d %s\n", idFlower, flower.GetState().c_str());
	}
	std::printf("садовод #%d ушел от цветочка #%d\n", idGardener, idFlower);
}
