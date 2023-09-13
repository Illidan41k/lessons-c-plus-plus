#include "Actions.h"

void handleDialogPart(std::shared_ptr<DialogPart> part, std::shared_ptr<GlobalTriggerManager> triggersManager)
{
	auto& answers = part->getAnswers();

	auto& question = part->GetQuestion();

	std::cout << question << std::endl << std::endl;

	int answerIndex{ 1 };

	for (const auto& answer : answers)
	{
		std::cout << "[" << answerIndex << "]: " << answer << std::endl;

		answerIndex++;
	}

	int choice;

	std::cin >> choice;

	auto choisedAnswer = *std::next(answers.begin(), choice - 1);

	auto trigger = part->GetTrigger(choisedAnswer);

	//std::cout << "choice:" << choisedAnswer << std::endl;

	//std::cout << trigger->id << std::endl;

	triggersManager->at(trigger->id)->value += trigger->value;

	std::cout << "test: " << triggersManager->at(trigger->id)->value << std::endl;
}

void handleStage(std::shared_ptr<SensebleStage> stage, std::shared_ptr < GlobalTriggerManager> triggersManager)
{
	auto possibleDialogs = stage->GetDialogsVariants();

	int closestDistance = 1000;

	std::shared_ptr<DialogPart> bestVariant{ nullptr };

	for (auto& dialog : possibleDialogs)
	{
		auto& trigger = dialog.first;
		auto& executor = dialog.second;

		int distance = abs(trigger->value - triggersManager->at(trigger->id)->value);


		std::cout << trigger->id << "  " << trigger->value <<"  "<< distance << std::endl;

		if (distance < closestDistance)
		{
			closestDistance = distance;
			bestVariant = executor;

			
		}
	}

	handleDialogPart(bestVariant, triggersManager);

}
