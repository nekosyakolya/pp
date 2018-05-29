#pragma once
class CFlowerConditionGenerator
{
public:
	CFlowerConditionGenerator();
	static DWORD WINAPI Execute(LPVOID data);
	~CFlowerConditionGenerator();
private:
	static bool IsAnEvenRandomNumber();
};

