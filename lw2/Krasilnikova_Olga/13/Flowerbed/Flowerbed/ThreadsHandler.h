#pragma once

class CThreadsHandler
{
public:
	void AddThread(HANDLE const& thread);
	void Execute();
	~CThreadsHandler();

private:
	void Close();
	std::vector<HANDLE> m_threads;
};
