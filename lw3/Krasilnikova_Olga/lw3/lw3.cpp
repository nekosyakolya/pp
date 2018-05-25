#include "stdafx.h"

#include "CalculateNumberPi.h"
#include "Point.h"

namespace
{
const int NUMBER_ARGUMENTS = 2;
} // namespace

int main(int argc, char* argv[])
{
	try
	{
		unsigned startTime = clock();

		if (argc != NUMBER_ARGUMENTS)
		{
			throw std::logic_error("Incorrect number of arguments\n");
		}

		int numberIterations = std::atoi(argv[1]);
		if (numberIterations == 0)
		{
			throw std::logic_error("Incorrect number of iterations\n");
		}
		CCalculateNumberPi calculate;
		calculate.Calculate(numberIterations);
		unsigned endTime = clock();

		std::cout << "Pi: " << calculate.GetPi() << std::endl;
		std::cout << "Time: " << endTime - startTime << std::endl;
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
