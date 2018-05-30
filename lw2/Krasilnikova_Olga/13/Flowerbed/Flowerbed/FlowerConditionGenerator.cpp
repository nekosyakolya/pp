#include "stdafx.h"
#include "FlowerConditionGenerator.h"
#include "ThreadData.h"

std::mt19937& CFlowerConditionGenerator::m_generator = CRandomGenerator::get();

DWORD WINAPI CFlowerConditionGenerator::Execute(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	while (true)
	{
		WaitForSingleObject(threadData->mutex, INFINITE);

		auto i = GetRandomIndex(threadData->flowerbed->size());
		auto& currentFlower = (threadData->flowerbed)->at(i);

		if (!currentFlower.IsFlaccidFlower())
		{
			if (IsAnEvenRandomNumber())
			{
				currentFlower.SetState(FlowerState::FLACCID);
				std::printf("цветочек #%d %s\n", static_cast<int>(currentFlower.GetId()), currentFlower.GetState().c_str());
			}
		}

		ReleaseMutex(threadData->mutex);
	}
	return 0;
}

bool CFlowerConditionGenerator::IsAnEvenRandomNumber()
{
	std::uniform_int_distribution<int> range(0);
	return range(m_generator) % 2 == 0;
}

int CFlowerConditionGenerator::GetRandomIndex(size_t size)
{
	int max = (size == 0) ? 0 : static_cast<int>(size - 1);
	std::uniform_int_distribution<int> range(0, max);
	return range(m_generator);
}
