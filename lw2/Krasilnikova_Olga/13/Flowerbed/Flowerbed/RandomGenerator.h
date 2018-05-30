#pragma once
#include <random>
#include <chrono>

class CRandomGenerator
{
public:
	static std::mt19937 & get();

private:
	CRandomGenerator();
	~CRandomGenerator() = default;
	static CRandomGenerator& instance();

	CRandomGenerator(CRandomGenerator const&) = delete;
	CRandomGenerator& operator= (CRandomGenerator const&) = delete;

	std::mt19937 m_generator;
};

