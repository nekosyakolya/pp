#include "stdafx.h"

#include "CMultiThreadCalculateNumberPi.h"
#include "CalculateFactory.h"
#include "CalculateNumberPi.h"
#include "Point.h"

int main(int argc, char* argv[])
{
	try
	{
		unsigned startTime = clock();
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
	catch (std::exception const& e)
	{
		std::cerr << e.what();
	}

	return 0;
}
