#pragma once
#include "CalculateNumberPi.h"
#include "ThreadsHandler.h"
#include <memory>

class CMultiThreadedCalculateNumberPi : public CCalculateNumberPi
{
public:
	CMultiThreadedCalculateNumberPi(size_t);

	void Calculate(size_t) override;

private:
	std::unique_ptr<CThreadsHandler> m_threadsHandler;

	size_t m_numberOfThreads = 0;
	size_t m_numberOfInnerPoint = 0;
};
