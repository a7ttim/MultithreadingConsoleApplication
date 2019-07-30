#include "ThreadInfo.h"

ThreadInfo::ThreadInfo(const std::string& name, const int& order, const int& amount)
	: m_name(name),
	m_order(order),
	m_amount(amount)
{
#ifdef _DEBUG
	std::cout << "Created\n";
#endif // _DEBUG
}

ThreadInfo::~ThreadInfo()
{
#ifdef _DEBUG
	std::cout << "Deleted\n";
#endif // _DEBUG
}


std::string ThreadInfo::getInfo() const
{
	return m_name + "\t\t" + std::to_string(m_order) + "\t\t" + std::to_string(m_amount) + "\n";
}
