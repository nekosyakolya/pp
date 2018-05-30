#pragma once

enum class FlowerState
{
	FLOWERING,
	FLACCID
};

inline std::string ToString(const FlowerState& value)
{
	std::string state = "";
	switch (value)
	{
	case FlowerState::FLACCID:
		state = "увял";
		break;
	default:
		state = "расцвел";
		break;
	}

	return state;
}
