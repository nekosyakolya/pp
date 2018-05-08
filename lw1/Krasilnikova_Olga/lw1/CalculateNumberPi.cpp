#include "stdafx.h"
#include "CalculateNumberPi.h"

DWORD CCalculateNumberPi::HandleDots(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	for (size_t i = 0; i != threadData->numberIterations; ++i)
	{
		Point point;
		if (BelongsCircle(point))
		{
			InterlockedIncrement(threadData->numberInnerPoints);
		}
	}
	return 0;
}

void CCalculateNumberPi::SetNumberPi(size_t amountPointsInCircle, size_t amountPoints)
{
	m_pi = (double)amountPointsInCircle / amountPoints * COEFFICIENT;
}

CCalculateNumberPi::CCalculateNumberPi()
	: m_pi(0)
{
}

void CCalculateNumberPi::Calculate(size_t amountPoints)
{
	size_t amountPointsInCircle = 0;
	ThreadData data(amountPoints, &amountPointsInCircle);

	HandleDots(&data);

	SetNumberPi(amountPointsInCircle, amountPoints);
}

double CCalculateNumberPi::GetPi() const
{
	return m_pi;
}

bool CCalculateNumberPi::BelongsCircle(const Point& point)
{
	return pow(point.x, 2) + pow(point.y, 2) <= m_sideSquare;
}
