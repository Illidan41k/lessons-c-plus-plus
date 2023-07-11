#include "UsbProxyController.h"
#include <iostream>

UsbProxyController::UsbProxyController(const std::string& portName)
{
	m_portId = std::make_shared<std::string>(portName);
	m_history = std::make_shared<std::vector<std::string>>();
}


UsbProxyController::UsbProxyController(const UsbProxyController& other)
{
	m_portId = other.m_portId;
	m_history = std::make_shared<std::vector<std::string>>();
}


bool UsbProxyController::SendCommand(const std::string& command)
{
	if (command.size() == 0)
	{
		return false;
	}

	std::cout << "sending command: " << command << std::endl;
	m_history->push_back(command);

    return true;
}

void UsbProxyController::EchoHistory()
{
	std::cout << std::endl << "history: " << std::endl;

	for (const auto& request : *m_history)
	{
		std::cout << request << std::endl;
	}
}
