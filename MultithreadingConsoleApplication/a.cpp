#include "a.h"

A::A(const int& index, const std::string& thread_name)
	: m_a(index),
	m_thread_name(thread_name)
{
#ifdef _DEBUG
	std::cout << "Created\n";
#endif // _DEBUG
}

A::~A()
{
#ifdef _DEBUG
	std::cout << "Deleted\n";
#endif // _DEBUG
}

std::string A::getInfo() const
{
	return m_thread_name + "\t\t" + std::to_string(m_a) + "\n";
}
