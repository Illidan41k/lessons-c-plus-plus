#pragma once
#include <string>

class BestTestServer
{

public:
	BestTestServer() {};

	void operator()(const std::string& request, std::string& responce);
	void operator()(const std::string& request);
private:
	size_t m_totalCalls{ 0 };
};

