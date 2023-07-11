#pragma once
#include <string>
#include <memory>
#include <vector>

class UsbProxyController
{

public:
	UsbProxyController(const std::string& portName);
	UsbProxyController(const UsbProxyController& other);

	bool SendCommand(const std::string& command);
	void EchoHistory();

private:
	std::shared_ptr<std::string> m_portId{};
	std::shared_ptr<std::vector<std::string>> m_history;
};

