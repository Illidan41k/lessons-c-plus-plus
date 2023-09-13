#pragma once
#include <set>
#include <string>
#include <memory>
#include <map>
#include <optional>

#include "ProxyTrigger.h"



class DialogPart
{
public:
	DialogPart(const std::string& question, const std::set<std::string>& answers)
	{
		m_question = question;
		m_answers = answers;

		for (const auto& answer : answers)
		{
			m_answersTriggers[answer] = std::make_shared<ProxyTrigger>();
		}
	}

	std::set<std::string>& getAnswers()
	{
		return m_answers;
	}

	std::string& GetQuestion()
	{
		return m_question;
	}

	//void SetChoice(const std::string& choice)
	//{
	//	m_choice = choice;
	//}

	std::shared_ptr<ProxyTrigger> GetTrigger(const std::string& choice)
	{
		return m_answersTriggers[choice];
	}

	void SetTrigger(const std::string& answer, std::shared_ptr<ProxyTrigger> trigger)
	{
		m_answersTriggers[answer] = trigger;
	}

private:

	std::string m_question{};
	std::set<std::string> m_answers{};

	std::map<std::string, std::shared_ptr<ProxyTrigger>> m_answersTriggers{};

	//std::optional<std::string> m_choice;
};

