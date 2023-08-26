#include "Singleton.h"
#include <iostream>

Logger* Logger::m_instance{ nullptr };
std::mutex Logger::m_creationMutex;


Logger* Logger::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(m_creationMutex);

    if (m_instance == nullptr)
    {
        m_instance = new Logger(value);
    }

    return m_instance;
}

void ThreadOne() 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    auto singleton = Logger::GetInstance("QWERTY");
    std::cout << singleton->value() << std::endl;
}

void ThreadTwo() 
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto singleton = Logger::GetInstance("ZXCVBN");

    Logger::GetInstance("")->Log("assdasd");

    singleton->DoSomething();
    std::cout << singleton->value() << std::endl;
}

