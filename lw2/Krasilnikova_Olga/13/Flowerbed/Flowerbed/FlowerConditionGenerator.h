#pragma once
#include "RandomGenerator.h"

class CFlowerConditionGenerator
{
public:
	static DWORD WINAPI Execute(LPVOID data);

private:
	static bool IsAnEvenRandomNumber();
	static std::mt19937& m_generator;
	static int GetRandomIndex(size_t size);
};
