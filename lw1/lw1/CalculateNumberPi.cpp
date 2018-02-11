#include "stdafx.h"
#include "CalculateNumberPi.h"


CCalculateNumberPi::CCalculateNumberPi()
{
}


CCalculateNumberPi::~CCalculateNumberPi()
{
}

void CCalculateNumberPi::Calculate(double amountPoints)
{
	double amountPointsInCircle = 0;
	for (size_t i = 0; i <= amountPoints; ++i)
	{
		Point point;
		point.x = GetRandomNumber();
		point.y = GetRandomNumber();
		if (PointBelongsCircle(point))
		{
			++amountPointsInCircle;
		}
	}

	m_pi = (amountPointsInCircle / amountPoints) * 4;
}

double CCalculateNumberPi::GetPi() const
{
	return m_pi;
}

double CCalculateNumberPi::GetRandomNumber() const
{
	return (double)(rand()) / RAND_MAX;
}

bool CCalculateNumberPi::PointBelongsCircle(const Point & point) const
{
	return pow(point.x, 2) + pow(point.y, 2) <= m_sideSquare;
}
