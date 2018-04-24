#pragma once
#include "CalculateNumberPi.h"
#include "ThreadsHandler.h"

class CMultiThreadCalculateNumberPi : public CCalculateNumberPi
{
public:
	CMultiThreadCalculateNumberPi(size_t);

	void Calculate(size_t) override;

private:
	std::unique_ptr<CThreadsHandler> m_threadsHandler;

	size_t m_numberOfThreads = 0;
	size_t m_numberOfInnerPoint = 0;
};
