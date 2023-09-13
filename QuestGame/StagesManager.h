#pragma once
#include <map>
#include <memory>

#include "SensebleStage.h"

class StagesManager
{
public:
	static StagesManager* Instance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new StagesManager();
		}

		return m_instance;
	}

	std::shared_ptr< SensebleStage> AddStage()
	{
		m_allStages[nextIndex] = std::make_shared<SensebleStage>();

		nextIndex++;

		return m_allStages[nextIndex - 1];

	}


private:
	static StagesManager* m_instance;
	StagesManager() = default;

	size_t nextIndex{ 1 };

	std::map<size_t, std::shared_ptr< SensebleStage>> m_allStages{};
};