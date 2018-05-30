#include "stdafx.h"
#include "Gardener.h"

size_t CGardener::m_gardenerId = 0;

CGardener::CGardener()
	: m_id(++m_gardenerId)
{
}

void CGardener::WaterFlower(CFlower& flower)
{
	std::printf("садовод #%d пришел к  цветочку #%d\n", m_id, flower.GetId());

	if (flower.IsFlaccidFlower())
	{
		std::printf("садовод #%d поливает цветочек #%d\n", m_id, flower.GetId());
		flower.SetState(FlowerState::FLOWERING);
		std::printf("цветок #%d %s\n", flower.GetId(), flower.GetState().c_str());
	}
	std::printf("садовод #%d ушел от цветочка #%d\n", m_id, flower.GetId());
}
