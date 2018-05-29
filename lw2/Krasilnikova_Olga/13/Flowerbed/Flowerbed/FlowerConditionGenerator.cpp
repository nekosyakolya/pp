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
			//auto currentFlower = (threadData->m_flowers)->at(i);

			if (!(threadData->flowers)->at(i).IsFlaccidFlower())
			{
				if (IsAnEvenRandomNumber())
				{
					(threadData->flowers)->at(i).SetState(FlowerState::FLACCID);
					std::printf("цветочек #%d %s\n", (threadData->flowers)->at(i).GetId(), (threadData->flowers)->at(i).GetState().c_str());
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
