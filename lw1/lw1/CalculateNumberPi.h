#pragma once
class CCalculateNumberPi
{
public:
	CCalculateNumberPi();
	~CCalculateNumberPi();
	void Calculate(double);
	double GetPi() const;
private:
	const int m_sideSquare = 1;
	double m_pi = 0;
	double GetRandomNumber() const;
	bool PointBelongsCircle(const Point &) const;
};

