#pragma once
#include "Point.h"
#include <Windows.h>

struct ThreadData
{
	ThreadData(size_t iterations, size_t* innerPoints)
		: numberOfIterations(iterations)
		, numberOfInnerPoints(innerPoints)
	{
	}
	size_t numberOfIterations;
	size_t* numberOfInnerPoints;
};

class CCalculateNumberPi
{
public:
	virtual ~CCalculateNumberPi() = default;
	CCalculateNumberPi();
	virtual void Calculate(size_t);
	double GetPi() const;

private:
	static const int m_sideSquare = 1;
	double m_pi;
	static bool BelongsCircle(const Point&);

protected:
	static DWORD HandleDots(LPVOID);
	void SetNumberPi(size_t, size_t);
};
