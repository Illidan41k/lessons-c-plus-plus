#pragma once
#include <memory>
#include <iostream>

#include "DialogPart.h"
#include "SensebleStage.h"
#include "GlobalTriggerManager.h"

void handleDialogPart(std::shared_ptr<DialogPart> part, std::shared_ptr < GlobalTriggerManager>  triggersManager);

void handleStage(std::shared_ptr<SensebleStage> stage, std::shared_ptr < GlobalTriggerManager> triggersManager);
