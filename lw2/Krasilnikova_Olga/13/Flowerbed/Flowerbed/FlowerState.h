#pragma once
enum class FlowerState
{
	FLOWERING,
	FLACCID
};


inline std::ostream& operator<<(std::ostream& str, const FlowerState& value)
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
	str << state;

	return str;
}


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


