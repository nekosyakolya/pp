#include "stdafx.h"

#include "Gardener.h"
#include "Flower.h"
#include "ThreadData.h"
#include "FlowerConditionGenerator.h"


namespace
{
	const static size_t TIME_SLEEP = 500;
	const static size_t NUMBER_FLOWERS = 4;
	const static size_t NUMBER_THREADS = 3;

}

DWORD WINAPI threadProc(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);

	CGardener gardener;

	while (true)
	{
		for (size_t i = 0; i < threadData->flowers->size(); ++i)
		{
			WaitForSingleObject(threadData->mutex, INFINITE);

			gardener.WaterFlower((threadData->flowers)->at(i));
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

	srand(time(NULL));

	std::vector<CFlower> flowers;
	for (size_t i = 0; i < NUMBER_FLOWERS; ++i)
	{
		flowers.emplace_back(CFlower());
	}
	
	HANDLE mutex = CreateMutex(NULL, false, NULL);

	HANDLE * threads = new HANDLE[NUMBER_THREADS];
	ThreadData threadData(&flowers, mutex);
	threads[0] = CreateThread(NULL, NULL, &CFlowerConditionGenerator::Execute, &threadData, NULL, NULL);

	for (size_t i = 1; i < NUMBER_THREADS; ++i)
	{
		threads[i] = CreateThread(NULL, NULL, threadProc, &threadData, NULL, NULL);
	}

	WaitForMultipleObjects(NUMBER_THREADS, threads, true, INFINITE);
	for (size_t i = 0; i < NUMBER_THREADS; ++i)
	{
		CloseHandle(threads);
	}

	CloseHandle(mutex);

	return 0;
}

