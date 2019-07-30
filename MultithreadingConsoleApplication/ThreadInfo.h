#pragma once

#include <iostream>
#include <string>

class ThreadInfo
{
	std::string m_name;
	int m_order;
	int m_amount;

public:
	ThreadInfo(const std::string& name, const int& order, const int& amount);
	~ThreadInfo();
	std::string getInfo() const;
};