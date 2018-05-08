#pragma once
#include "CalculateNumberPi.h"
#include "ThreadsHandler.h"

class CMultiThreadCalculateNumberPi : public CCalculateNumberPi
{
public:
	CMultiThreadCalculateNumberPi(size_t);

	void Calculate(size_t) override;

private:
	std::unique_ptr<CThreadsHandler> m_threadsHandlers;

	std::vector<ThreadData> CreateThreadsData(size_t);

	size_t m_numberThreads = 0;
	size_t m_numberInnerPoint = 0;
};
