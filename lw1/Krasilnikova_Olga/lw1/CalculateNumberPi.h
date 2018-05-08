#pragma once
#include "Point.h"
#include <Windows.h>

struct ThreadData
{
	ThreadData(size_t iterations, size_t* innerPoints)
		: numberIterations(iterations)
		, numberInnerPoints(innerPoints)
	{
	}
	size_t numberIterations;
	size_t* numberInnerPoints;
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
	const double COEFFICIENT = 4;
	static bool BelongsCircle(const Point&);

protected:
	static DWORD HandleDots(LPVOID);
	void SetNumberPi(size_t, size_t);
};
