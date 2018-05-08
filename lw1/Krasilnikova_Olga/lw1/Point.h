#pragma once
struct Point
{
public:
	Point():
		x(GetRandomNumber()),
		y(GetRandomNumber())
	{
	}
	double x = 0;
	double y = 0;
private:
	double GetRandomNumber() const
	{
		return (double)(rand()) / RAND_MAX;
	}
};
