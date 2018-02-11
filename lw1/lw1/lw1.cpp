#include "stdafx.h"


int main(int argc, char* argv[])
{
	try {
		/*if (argc != 2)
		{
			throw std::logic_error("");
		}*/
		CCalculateNumberPi calculate;
		calculate.Calculate(123);
		std::cout << calculate.GetPi() << std::endl;


	}
	catch (std::logic_error const &e)
	{
		std::cout << e.what();
	}

	return 0;
}

