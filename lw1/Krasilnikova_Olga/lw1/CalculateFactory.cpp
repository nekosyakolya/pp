#include "stdafx.h"
#include "CalculateFactory.h"

std::unique_ptr<CCalculateNumberPi> CCalculatorFactory::CreateCalculate(std::stringstream& description)
{
	std::string threadType;
	description >> threadType;

	auto result = CALCULATOR_CREATOR.find(threadType);

	if (result == CALCULATOR_CREATOR.end())
	{
		throw std::invalid_argument("Incorrect value of argument\n");
	}

	return result->second(description);
}

std::unique_ptr<CCalculateNumberPi> CCalculatorFactory::CreateCalculatorForSingleThread(std::stringstream& stream)
{
	return std::make_unique<CCalculateNumberPi>();
}

std::unique_ptr<CMultiThreadCalculateNumberPi> CCalculatorFactory::CreateCalculatorForMultiThread(std::stringstream& stream)
{
	size_t numberOfThreads = 0;
	const size_t MIN_WAIT_OBJECTS = 1;
	if (!(stream >> numberOfThreads))
	{
		throw std::invalid_argument("Incorrect number of arguments\n");
	}
	if (numberOfThreads <= MIN_WAIT_OBJECTS || numberOfThreads > MAXIMUM_WAIT_OBJECTS)
	{
		throw std::invalid_argument("Incorrect number of threads\n");
	}
	return std::make_unique<CMultiThreadCalculateNumberPi>(numberOfThreads);
}
