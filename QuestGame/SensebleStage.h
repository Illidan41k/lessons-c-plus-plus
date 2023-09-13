#pragma once
#include "DialogPart.h"
#include <vector>
#include <map>
#include <memory>


class SensebleStage
{
public:

	void Connect(std::shared_ptr<ProxyTrigger> trigger, std::shared_ptr<DialogPart> nextPart)
	{
		m_nextDialogs.push_back(std::make_pair(trigger, nextPart));
	}

	std::vector<std::pair<std::shared_ptr<ProxyTrigger>, std::shared_ptr<DialogPart>>>& GetDialogsVariants()
	{
		return m_nextDialogs;
	}


private:
	std::vector<std::pair<std::shared_ptr<ProxyTrigger>, std::shared_ptr<DialogPart>>> m_nextDialogs{};
};

