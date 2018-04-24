#pragma once

#include "CMultiThreadCalculateNumberPi.h"
#include "CalculateNumberPi.h"

class CCalculatorFactory
{
public:
	CCalculatorFactory();
	std::unique_ptr<CCalculateNumberPi> CreateCalculate(std::stringstream& description);
	~CCalculatorFactory();

private:
	using CalculatorCreator = std::function<std::unique_ptr<CCalculateNumberPi>(std::stringstream& stream)>;
	std::unique_ptr<CCalculateNumberPi> CreateCalculatorForSingleThread(std::stringstream& stream);
	std::unique_ptr<CMultiThreadCalculateNumberPi> CreateCalculatorForMultiThread(std::stringstream& stream);

	const std::unordered_map<std::string, CalculatorCreator> CALCULATOR_CREATOR = {
		{ "multi", std::bind(&CCalculatorFactory::CreateCalculatorForMultiThread, this, std::placeholders::_1) },
		{ "single", std::bind(&CCalculatorFactory::CreateCalculatorForSingleThread, this, std::placeholders::_1) }
	};
};
