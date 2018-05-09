#include "stdafx.h"

#include "CMultiThreadCalculateNumberPi.h"
#include "CalculateFactory.h"
#include "CalculateNumberPi.h"
#include "Point.h"

namespace
{
const size_t MIN_WAIT_OBJECTS = 1;
const int MIN_NUMBER_ARGUMENTS = 2;
const std::string HELP = "--help";
} // namespace

void PrintInfo()
{
	std::cout << "The program takes two arguments in single-threaded mode:" << std::endl;
	std::cout << "first argument: \"single\"" << std::endl;
	std::cout << "second argument: number of iterations" << std::endl;

	std::cout << "The program takes three arguments in multi-threaded mode:" << std::endl;
	std::cout << "first argument: \"multi\"" << std::endl;
	std::cout << "second argument: number of threads. Should be from " << MIN_WAIT_OBJECTS << " to " << MAXIMUM_WAIT_OBJECTS << std::endl;
	std::cout << "third argument: number of iterations" << std::endl;
}
int main(int argc, char* argv[])
{
	try
	{
		unsigned startTime = clock();

		if (argc == MIN_NUMBER_ARGUMENTS && argv[1] == HELP)
		{
			PrintInfo();
		}
		else
		{
			std::stringstream s;
			for (size_t i = 1; i != argc; ++i)
			{
				s << argv[i] << " ";
			}
			CCalculatorFactory factory;
			std::unique_ptr<CCalculateNumberPi> calculate = factory.CreateCalculate(s);

			size_t numberIterations;
			if (!(s >> numberIterations))
			{
				throw std::invalid_argument("Incorrect number of arguments\n");
			}

			calculate->Calculate(numberIterations);
			unsigned endTime = clock();

			std::cout << "Pi: " << calculate->GetPi() << std::endl;
			std::cout << "Time: " << endTime - startTime << std::endl;
		}
	}
	catch (std::exception const& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
