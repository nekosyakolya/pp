#pragma once
class CThreadsHandler
{
public:
	CThreadsHandler();
	void AddThread(HANDLE const& thread);
	void Execute();
	~CThreadsHandler();
private:
	void Close();
	std::vector<HANDLE> m_threads;
};

