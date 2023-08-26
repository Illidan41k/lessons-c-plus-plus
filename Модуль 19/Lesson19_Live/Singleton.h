#pragma once
#include <string>
#include <mutex>

class Logger
{

public:

    Logger(Logger& other) = delete;

    void operator=(const Logger&) = delete;

    static Logger* GetInstance(const std::string& value);

    void DoSomething()
    {
        // lalalalalallalaallala
        //very isefull method
    }

    std::string value() const
    {
        return m_value;
    }

    void Log(const std::string& message) {};
protected:
    Logger(const std::string value) : m_value(value)
    {
    }
    ~Logger() {}
    std::string m_value;

private:
    static Logger* m_instance;
    static std::mutex m_creationMutex;
};


void ThreadOne();

void ThreadTwo();