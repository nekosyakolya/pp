#include "stdafx.h"

#include "Gardener.h"
#include "Flower.h"
#include "ThreadData.h"
#include "FlowerConditionGenerator.h"



DWORD WINAPI threadProc(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);

	CGardener gardener;

	while (true)
	{
		for (size_t i = 0; i < threadData->m_flowers->size(); ++i)
		{
			gardener.WaterFlower((threadData->m_flowers)->at(i));
		}
	}

	return 0;
}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL));

	std::vector<CFlower> flowers;
	for (size_t i = 0; i < 4; ++i)
	{
		flowers.emplace_back(CFlower());
	}
	auto flowersData = ThreadData(&flowers);
	auto generator = CreateThread(NULL, NULL, &CFlowerConditionGenerator::Execute, &flowersData, NULL, NULL);

	HANDLE * threads = new HANDLE[2];
	ThreadData threadData(&flowers);
	for (size_t i = 0; i < 2; i++)
	{
		threads[i] = CreateThread(NULL, 0, threadProc, &threadData, 0, NULL);
	}

	WaitForMultipleObjects(2, threads, true, INFINITE);
	for (size_t i = 0; i < 2; i++)
	{
		CloseHandle(threads);
	}

	WaitForSingleObject(generator, INFINITE);
	CloseHandle(generator);

	return 0;
}

