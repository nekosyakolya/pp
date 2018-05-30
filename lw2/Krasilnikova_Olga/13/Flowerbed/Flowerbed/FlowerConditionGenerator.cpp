#include "stdafx.h"
#include "FlowerConditionGenerator.h"
#include "ThreadData.h"

std::mt19937 &CFlowerConditionGenerator::m_generator = CRandomGenerator::get();

CFlowerConditionGenerator::CFlowerConditionGenerator()
{
}

DWORD WINAPI CFlowerConditionGenerator::Execute(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	while (true)
	{
		WaitForSingleObject(threadData->mutex, INFINITE);
		
		auto i = GetRandomIndex(threadData->flowerbed->size());
		auto &currentFlower = (threadData->flowerbed)->at(i);

		if (!currentFlower.IsFlaccidFlower())
		{
			if (IsAnEvenRandomNumber())
			{
				currentFlower.SetState(FlowerState::FLACCID);
				std::printf("цветочек #%d %s\n", currentFlower.GetId(), currentFlower.GetState().c_str());
			}
		}

		ReleaseMutex(threadData->mutex);
	}
	return 0;
}


CFlowerConditionGenerator::~CFlowerConditionGenerator()
{
}

bool CFlowerConditionGenerator::IsAnEvenRandomNumber()
{
	std::uniform_int_distribution<int> range(0);
	auto i = range(m_generator);
	return i % 2 == 0;
}

int CFlowerConditionGenerator::GetRandomIndex(size_t size)
{
	int max = (size == 0) ? 0 : (size - 1);
	std::uniform_int_distribution<int> range(0, max);
	return range(m_generator);
}
