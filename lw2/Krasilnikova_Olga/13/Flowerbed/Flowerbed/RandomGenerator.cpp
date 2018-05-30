#include "stdafx.h"
#include "RandomGenerator.h"

CRandomGenerator::CRandomGenerator() {
	std::random_device rd;

	if (rd.entropy() != 0) {
		std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		m_generator.seed(seed);
	}
	else {
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		m_generator.seed(seed);
	}
}

CRandomGenerator& CRandomGenerator::instance() {
	static CRandomGenerator generator;
	return generator;
}

std::mt19937 & CRandomGenerator::get() {
	return CRandomGenerator::instance().m_generator;
}