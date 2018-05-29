#include "stdafx.h"
#include "RandomGenerator.h"

CRandomGenerator::CRandomGenerator() {
	std::random_device rd;

	if (rd.entropy() != 0) {
		std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		mMt.seed(seed);
	}
	else {
		auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
		mMt.seed(seed);
	}
}

CRandomGenerator& CRandomGenerator::instance() {
	static CRandomGenerator s;
	return s;
}

std::mt19937 & CRandomGenerator::getMt19937() {
	return CRandomGenerator::instance().mMt;
}