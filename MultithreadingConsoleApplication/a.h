#pragma once

#include <iostream>
#include <string>

#include "Resource.h"

class A {
	int m_a;
	const std::string m_thread_name;

public:
	A(const int &index, const std::string &thread_name);
	~A();

	std::string getInfo() const;
};