#pragma once

#include <mutex>
#include <condition_variable>
#include <iostream>

class Factory {
    enum class Status 
    { 
        idle,
        comeFromCustomer,
        newOrder, 
        ready 
    };

public:

    void Adjuster() 
    {
        while (true)
        {
            std::unique_lock<std::mutex> currentOrderLock(m_currentOrderMutex);
            m_orderStatusChange.wait(currentOrderLock, [=]() { return m_orderStatus == Status::newOrder; });

            m_orderStatus = Status::ready;
            m_orderStatusChange.notify_one();
            std::cout << "worker completed task" << std::endl;
        }     
    }

    void Master()
    {
        while (true)
        {
            std::unique_lock<std::mutex> newOrderLock(m_newOrderMutex);
            m_orderStatusChange.wait(newOrderLock, [=]() { return m_orderStatus == Status::comeFromCustomer; });

            {
                std::lock_guard<std::mutex> lock(m_currentOrderMutex);
                m_orderStatus = Status::newOrder;
                std::cout << "master created new order" << std::endl;
                m_orderStatusChange.notify_one();
            }

            std::unique_lock<std::mutex> currentOrderLock(m_currentOrderMutex);
            m_orderStatusChange.wait(currentOrderLock, [=]() { return m_orderStatus == Status::ready; });
            m_orderStatus = Status::idle;
            currentOrderLock.unlock();
            std::cout << "master checked order. All is ok!" << std::endl;
        }
       
    }

    void AskNewOrder()
    {
        std::lock_guard<std::mutex> locker(m_newOrderMutex);
        m_orderStatus = Status::comeFromCustomer;
        m_orderStatusChange.notify_one();
    }

private:
    Status m_orderStatus = Status::idle;

    std::mutex m_currentOrderMutex;
    std::mutex m_newOrderMutex;

    std::condition_variable m_orderStatusChange;
};
