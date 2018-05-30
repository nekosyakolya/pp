#include "stdafx.h"

#include "Flower.h"
#include "FlowerConditionGenerator.h"
#include "Gardener.h"
#include "ThreadData.h"
#include "ThreadsHandler.h"

namespace
{
const static size_t TIME_SLEEP = 50;
const static size_t NUMBER_FLOWERS = 5;
const static size_t NUMBER_THREADS = 3;
} // namespace

DWORD WINAPI Process(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	CGardener gardener;

	while (true)
	{
		auto size = threadData->flowerbed->size();
		for (size_t i = 0; i < size; ++i)
		{
			WaitForSingleObject(threadData->mutex, INFINITE);

			gardener.WaterFlower((threadData->flowerbed)->at(i));

			ReleaseMutex(threadData->mutex);
		}

		Sleep(TIME_SLEEP);
	}
	return 0;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::vector<CFlower> flowerbed;
	for (size_t i = 0; i < NUMBER_FLOWERS; ++i)
	{
		flowerbed.emplace_back(CFlower());
	}

	HANDLE mutex = CreateMutex(NULL, false, NULL);
	CThreadsHandler threadsHandler;

	ThreadData threadData(&flowerbed, mutex);
	threadsHandler.AddThread(CreateThread(NULL, NULL, &CFlowerConditionGenerator::Execute, &threadData, NULL, NULL));

	for (size_t i = 1; i < NUMBER_THREADS; ++i)
	{
		threadsHandler.AddThread(CreateThread(NULL, NULL, Process, &threadData, NULL, NULL));
	}

	threadsHandler.Execute();
	CloseHandle(mutex);

	return 0;
}
