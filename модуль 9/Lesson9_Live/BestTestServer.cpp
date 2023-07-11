#include "BestTestServer.h"
#include <sstream>
#include <iostream>

void BestTestServer::operator()(const std::string& request, std::string& responce)
{
	m_totalCalls++;

	std::ostringstream responceBody;
	responceBody << "this is " << m_totalCalls << " call.";
	responce = responceBody.str();
	std::cout << responce << std::endl;
}

void BestTestServer::operator()(const std::string& request)
{
	m_totalCalls++;
	//....
	
	std::cout << "this is " << m_totalCalls << " call...................";

}
