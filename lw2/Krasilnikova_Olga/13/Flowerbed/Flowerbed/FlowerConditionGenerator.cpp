#include "stdafx.h"
#include "FlowerConditionGenerator.h"
#include "ThreadData.h"

HANDLE CFlowerConditionGenerator::m_mutex = CreateMutex(NULL, false, NULL);
CFlowerConditionGenerator::CFlowerConditionGenerator()
{
}

DWORD WINAPI CFlowerConditionGenerator::Execute(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	while (true)
	{
		/*for (size_t i = 0; i < threadData->m_flowers->size(); ++i)
		{*/
			// если цветок увял,то рандомим состояние
			WaitForSingleObject(m_mutex, INFINITE);
			auto i = rand() % threadData->m_flowers->size();

			if (!(threadData->m_flowers)->at(i).IsFlaccidFlower())
			{
				auto coefficient = rand();
				if (coefficient % 5 == 0)
				{

					(threadData->m_flowers)->at(i).SetState(FlowerState::FLACCID);
					std::printf("цветочек #%d %s\n", (threadData->m_flowers)->at(i).GetId(), (threadData->m_flowers)->at(i).GetState().c_str());


				}
			}
			ReleaseMutex(m_mutex);
			Sleep(500);
		//}
	}


	return 0;
}


CFlowerConditionGenerator::~CFlowerConditionGenerator()
{
	//ReleaseMutex(m_mutex);

	CloseHandle(m_mutex);
}
