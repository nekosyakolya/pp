#include "stdafx.h"
#include "FlowerConditionGenerator.h"
#include "ThreadData.h"

std::mt19937 &CFlowerConditionGenerator::mt = CRandomGenerator::getMt19937();
CFlowerConditionGenerator::CFlowerConditionGenerator()
{
}

DWORD WINAPI CFlowerConditionGenerator::Execute(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	while (true)
	{
			WaitForSingleObject(threadData->mutex, INFINITE);
			int max = threadData->flowers->size() - 1;//todo
			std::uniform_int_distribution<int> range(0, max);

			auto i = range(mt);
			
			auto &currentFlower = (threadData->flowers)->at(i);

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
	std::uniform_int_distribution<int> range(0, 443);

	auto i = range(mt);
	return i % 2 == 0;
}
