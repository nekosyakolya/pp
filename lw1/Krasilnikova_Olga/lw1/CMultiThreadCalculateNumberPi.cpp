#include "stdafx.h"
#include "CMultiThreadCalculateNumberPi.h"

CMultiThreadCalculateNumberPi::CMultiThreadCalculateNumberPi(size_t numberThreads)
	: CCalculateNumberPi()
	, m_threadsHandlers(std::make_unique<CThreadsHandler>())
	, m_numberThreads(numberThreads)
{
}

void CMultiThreadCalculateNumberPi::Calculate(size_t numberPoints)
{
	std::vector<ThreadData> threadsData = CreateThreadsData(numberPoints);

	for (size_t i = 0; i < m_numberThreads; ++i)
	{
		if (threadsData.at(i).numberIterations != 0)
		{
			m_threadsHandlers->AddThread(CreateThread(NULL, NULL, &HandleDots, &threadsData.at(i), NULL, NULL));
		}
	}
	m_threadsHandlers->Execute();

	SetNumberPi(m_numberInnerPoint, numberPoints);
}

std::vector<ThreadData> CMultiThreadCalculateNumberPi::CreateThreadsData(size_t numberPoints)
{
	size_t numberIterationsInThread = numberPoints / m_numberThreads;
	ThreadData data(numberIterationsInThread, &m_numberInnerPoint);

	std::vector<ThreadData> threadsData = std::vector<ThreadData>(m_numberThreads, data);
	size_t freeIterations = numberPoints % m_numberThreads;
	for (size_t i = 0; i < freeIterations; ++i)
	{
		++(threadsData.at(i).numberIterations);
	}

	return threadsData;
}
