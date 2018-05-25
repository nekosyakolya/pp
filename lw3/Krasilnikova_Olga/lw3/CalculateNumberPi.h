#pragma once
#include "Point.h"

class CCalculateNumberPi
{
public:
	CCalculateNumberPi();
	virtual void Calculate(int);
	double GetPi() const;

private:
	const int m_sideSquare = 1;
	double m_pi;
	size_t m_amountPointsInCircle;
	const double COEFFICIENT = 4;
	bool BelongsCircle(const Point&);
	void HandleDots(int);
};
