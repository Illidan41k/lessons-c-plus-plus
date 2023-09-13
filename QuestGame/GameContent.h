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
		auto firstDialog = m_dialogsManager->AddSpeech("������, �����. ������� � ���� ������",
			{
				"��� �����",
				"������??",
				"������ �����!"
			});

		firstDialog->SetTrigger("��� �����", std::make_shared<ProxyTrigger>("������ �������", 3));
		firstDialog->SetTrigger("������??", std::make_shared<ProxyTrigger>("����� �������", 2));
		firstDialog->SetTrigger("������ �����!", std::make_shared<ProxyTrigger>("����� �������", 3));

		handleDialogPart(firstDialog, m_triggerManager);
	}

	void Firstlayer()
	{
		auto badDialog = m_dialogsManager->AddSpeech("� ������� ���! ��� ����� ����� �����.",
			{
				"�-�-�-�..."
			});

		auto stupidDialog = m_dialogsManager->AddSpeech("������. � ������ � ���� �� ������� ������ ����?",
			{
				"������ ���",
				"� � ��� ���� �������"
			});

		stupidDialog->SetTrigger("������ ���", m_triggerManager->createAt("��������� �������", 2));
		stupidDialog->SetTrigger("� � ��� ���� �������", m_triggerManager->createAt("����� �������", 1));

		auto stage = m_stagesManager->AddStage();
		stage->Connect(std::make_shared<ProxyTrigger>("������ �������", 2), badDialog);
		stage->Connect(std::make_shared<ProxyTrigger>("����� �������", 2), stupidDialog);

		m_stages.push_back(stage);

		handleStage(stage, m_triggerManager);
	}

	std::shared_ptr<GlobalTriggerManager> m_triggerManager = std::make_shared< GlobalTriggerManager>();

	DialogManager* m_dialogsManager = DialogManager::Instance();

	StagesManager* m_stagesManager = StagesManager::Instance();


	std::vector<std::shared_ptr<SensebleStage>> m_stages{};
};

