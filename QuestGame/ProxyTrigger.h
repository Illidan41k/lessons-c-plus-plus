#pragma once
#include <string>

struct ProxyTrigger
{
	ProxyTrigger(const std::string& key, int value)
	{
		this->id = key;
		this->value = value;
	}

	ProxyTrigger() = default;

	std::string id{};
	int value{0};
};

