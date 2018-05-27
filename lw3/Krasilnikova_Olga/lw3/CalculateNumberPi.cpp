#include "stdafx.h"
#include "CalculateNumberPi.h"

void CCalculateNumberPi::HandleDots(int amountPoints)
{
#pragma omp parallel for
	for (int i = 0; i < amountPoints; ++i)
	{
		Point point;
		if (BelongsCircle(point))
		{
#pragma omp atomic
			++m_amountPointsInCircle;
		}
	}
}

CCalculateNumberPi::CCalculateNumberPi()
	: m_pi(0)
	, m_amountPointsInCircle(0)
{
}

void CCalculateNumberPi::Calculate(int amountPoints)
{
	HandleDots(amountPoints);
	m_pi = (double)m_amountPointsInCircle / amountPoints * COEFFICIENT;
}

double CCalculateNumberPi::GetPi() const
{
	return m_pi;
}

bool CCalculateNumberPi::BelongsCircle(const Point& point)
{
	return pow(point.x, 2) + pow(point.y, 2) <= m_sideSquare;
}
