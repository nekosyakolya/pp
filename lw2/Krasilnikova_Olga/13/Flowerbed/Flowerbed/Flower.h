#pragma once
#include "FlowerState.h"
class CFlower
{
public:
	CFlower();
	bool IsFlaccidFlower()const;
	size_t GetId()const;
	std::string GetState()const;
	void SetState(const FlowerState &state);
	~CFlower();
private:
	FlowerState m_state;
	size_t m_id;
	static size_t m_flowerId;

};

