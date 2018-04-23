#include "stdafx.h"

#include "CalculateNumberPi.h"
#include "MultiThreadedCalculateNumberPi.h"
#include "Point.h"

int main(int argc, char* argv[])
{
	try
	{

		CCalculateNumberPi calculate;

		calculate.Calculate(123);
		std::cout << calculate.GetPi() << std::endl;

		CMultiThreadedCalculateNumberPi calc(4);
		calc.Calculate(123);
		std::cout << calc.GetPi() << std::endl;
	}
	catch (std::logic_error const& e)
	{
		std::cout << e.what();
	}

	return 0;
}
