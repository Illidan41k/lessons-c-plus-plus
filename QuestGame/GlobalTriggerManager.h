#pragma once
#include "ProxyTrigger.h"
#include <map>
#include <string>
#include <memory>


class GlobalTriggerManager
{
public:

	std::shared_ptr<ProxyTrigger> at(const std::string& key)
	{
		if (m_globalTriggers.find(key) == m_globalTriggers.end())
		{
			m_globalTriggers[key] = std::make_shared<ProxyTrigger>();
		}
		
		return m_globalTriggers[key];
	}

	std::shared_ptr<ProxyTrigger> createAt(const std::string& key, int value)
	{
		m_globalTriggers[key] = std::make_shared<ProxyTrigger>(key, value);

		return m_globalTriggers[key];
	}

private:
	std::map<std::string, std::shared_ptr<ProxyTrigger>> m_globalTriggers{};
};

