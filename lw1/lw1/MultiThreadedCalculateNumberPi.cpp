#include "stdafx.h"
#include "MultiThreadedCalculateNumberPi.h"

CMultiThreadedCalculateNumberPi::CMultiThreadedCalculateNumberPi(size_t numberOfThreads)
	: CCalculateNumberPi()
	, m_threadsHandler(std::make_unique<CThreadsHandler>())
	, m_numberOfThreads(numberOfThreads)
{
}

void CMultiThreadedCalculateNumberPi::Calculate(size_t amountPoints)
{

	size_t numberOfIterationsAtThread = amountPoints / m_numberOfThreads;
	ThreadData data(numberOfIterationsAtThread, &m_numberOfInnerPoint);

	std::vector<ThreadData> threadsData = std::vector<ThreadData>(m_numberOfThreads, data);
	size_t freeIterations = amountPoints % m_numberOfThreads;
	for (size_t i = 0; i < freeIterations; ++i)
	{
		++(threadsData.at(i).numberOfIterations);
	}
	for (size_t i = 0; i < m_numberOfThreads; ++i)
	{
		if (threadsData.at(i).numberOfIterations != 0)
		{

			m_threadsHandler->AddThread(CreateThread(NULL, NULL, &HandleDots, &threadsData.at(i), NULL, NULL));
		}
	}
	m_threadsHandler->Execute();

	SetNumberPi(m_numberOfInnerPoint, amountPoints);
}
