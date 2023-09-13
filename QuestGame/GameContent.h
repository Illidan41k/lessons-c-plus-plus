#pragma once
#include "GlobalTriggerManager.h"
#include "DialogManager.h"
#include "Actions.h"
#include "StagesManager.h"

class GameContent
{
public:
	GameContent()
	{
		ZeroLayer();
		Firstlayer();
	}


private:

	void ZeroLayer()
	{
		auto firstDialog = m_dialogsManager->AddSpeech("Дарова, щегол. Сегодня с тебя подвиг",
			{
				"сам щегол",
				"подвиг??",
				"всегда готов!"
			});

		firstDialog->SetTrigger("сам щегол", std::make_shared<ProxyTrigger>("борзый воитель", 3));
		firstDialog->SetTrigger("подвиг??", std::make_shared<ProxyTrigger>("тупой воитель", 2));
		firstDialog->SetTrigger("всегда готов!", std::make_shared<ProxyTrigger>("тупой воитель", 3));

		handleDialogPart(firstDialog, m_triggerManager);
	}

	void Firstlayer()
	{
		auto badDialog = m_dialogsManager->AddSpeech("В темницу его! Мне нужен новый герой.",
			{
				"ы-ы-ы-ы..."
			});

		auto stupidDialog = m_dialogsManager->AddSpeech("Слушай. А почему у тебя из снаряги только руки?",
			{
				"Пропил меч",
				"я и так всех порешаю"
			});

		stupidDialog->SetTrigger("Пропил меч", m_triggerManager->createAt("ненадёжный воитель", 2));
		stupidDialog->SetTrigger("я и так всех порешаю", m_triggerManager->createAt("тупой воитель", 1));

		auto stage = m_stagesManager->AddStage();
		stage->Connect(std::make_shared<ProxyTrigger>("борзый воитель", 2), badDialog);
		stage->Connect(std::make_shared<ProxyTrigger>("тупой воитель", 2), stupidDialog);

		m_stages.push_back(stage);

		handleStage(stage, m_triggerManager);
	}

	std::shared_ptr<GlobalTriggerManager> m_triggerManager = std::make_shared< GlobalTriggerManager>();

	DialogManager* m_dialogsManager = DialogManager::Instance();

	StagesManager* m_stagesManager = StagesManager::Instance();


	std::vector<std::shared_ptr<SensebleStage>> m_stages{};
};

