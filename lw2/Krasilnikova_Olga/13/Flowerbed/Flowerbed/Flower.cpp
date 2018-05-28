#include "stdafx.h"
#include "Flower.h"

size_t CFlower::m_flowerId = 0;

CFlower::CFlower() :
	m_state(FlowerState::FLOWERING),
	m_id(++m_flowerId)
{
}

bool CFlower::IsFlaccidFlower() const
{
	return m_state == FlowerState::FLACCID;
}

size_t CFlower::GetId() const
{
	return m_id;
}

std::string CFlower::GetState() const
{
	return ToString(m_state);
}

void CFlower::SetState(const FlowerState & state)
{
	//std::printf("цветочек #%d %s\n", m_id, ToString(state).c_str());

	m_state = state;
}


CFlower::~CFlower()
{
}
