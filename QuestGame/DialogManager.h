#pragma once
#include "DialogPart.h"
#include <map>
#include <memory>


class DialogManager
{
public:
	static DialogManager* Instance()
	{
		if (m_instance == nullptr)
		{
			m_instance = new DialogManager();
		}

		return m_instance;
	}

	std::shared_ptr<DialogPart> AddSpeech(const std::string& question, const std::set<std::string>& answers)
	{
		m_allDialogs[nextIndex] = std::make_shared< DialogPart>(question, answers);

		nextIndex++;

		return m_allDialogs[nextIndex - 1];
	}

private:
	static DialogManager* m_instance;
	DialogManager() = default;

	size_t nextIndex{ 1 };

	std::map<size_t, std::shared_ptr< DialogPart>> m_allDialogs{};
};

