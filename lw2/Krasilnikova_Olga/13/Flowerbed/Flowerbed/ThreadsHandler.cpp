#include "stdafx.h"
#include "ThreadsHandler.h"

CThreadsHandler::CThreadsHandler()
{
}

void CThreadsHandler::AddThread(HANDLE const& thread)
{
	m_threads.emplace_back(thread);
}

void CThreadsHandler::Execute()
{
	DWORD size = static_cast<DWORD>(m_threads.size());
	WaitForMultipleObjects(size, m_threads.data(), TRUE, INFINITE);
}

CThreadsHandler::~CThreadsHandler()
{
	Close();
}

void CThreadsHandler::Close()
{
	for (auto& thread : m_threads)
	{
		CloseHandle(thread);
	}
}
