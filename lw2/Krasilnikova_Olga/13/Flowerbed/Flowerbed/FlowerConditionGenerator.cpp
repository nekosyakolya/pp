#include "stdafx.h"
#include "FlowerConditionGenerator.h"
#include "ThreadData.h"
CFlowerConditionGenerator::CFlowerConditionGenerator()
{
}

DWORD WINAPI CFlowerConditionGenerator::Execute(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	while (true)
	{
			WaitForSingleObject(threadData->mutex, INFINITE);
			auto i = rand() % threadData->flowers->size();
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
			//Sleep(500);
	}

	return 0;
}


CFlowerConditionGenerator::~CFlowerConditionGenerator()
{
}

bool CFlowerConditionGenerator::IsAnEvenRandomNumber()
{
	auto number = rand();
	return number % 2 == 0;
}
