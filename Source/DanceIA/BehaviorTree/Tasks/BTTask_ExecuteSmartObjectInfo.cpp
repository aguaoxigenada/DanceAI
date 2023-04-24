#include "BehaviorTree/Tasks/BTTask_ExecuteSmartObjectInfo.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "AIModule/Classes/AIController.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Characters/DI_AICharacterBase.h"
#include "Controllers/DI_AIControllerBase.h"
#include "Controllers/Patrol/DI_PatrolAIController.h"

UBTTask_ExecuteSmartObjectInfo::UBTTask_ExecuteSmartObjectInfo() : Super()
{
	NodeName = "Execute Smart Object Info";
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_ExecuteSmartObjectInfo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	UBlackboardComponent* OwnerBlackboard = OwnerComp.GetBlackboardComponent();
	AAIController* OwnerController = OwnerComp.GetAIOwner();

	if (!OwnerBlackboard || !OwnerController)
	{
		return EBTNodeResult::Failed;
	}

	Controller = Cast<ADI_AIControllerBase>(OwnerController);

	ADI_AICharacterBase* Dancer = Cast<ADI_AICharacterBase>(OwnerController->GetPawn());
	if (!Dancer)
	{
		return EBTNodeResult::Failed;
	}

	SmartObject = Dancer->GetCurrentSmartObject();

	if (!SmartObject)
	{
		return EBTNodeResult::Failed;
	}

	if (SmartObject->SmartObjectInformation.AnimToPlay)
	{
		const float Duration = Dancer->PlayAnimMontage(SmartObject->SmartObjectInformation.AnimToPlay);
		Dancer->AnimDuration = Duration;
		SmartObject->GetWorldTimerManager().SetTimer(AnimationTimer, this, &UBTTask_ExecuteSmartObjectInfo::OnAnimationTimer, Duration, false);
		return EBTNodeResult::InProgress;
	}

	return EBTNodeResult::Succeeded;
}


void UBTTask_ExecuteSmartObjectInfo::OnAnimationTimer()
{
	if (Controller)
	{
		FinishLatentTask(*Controller->GetBehaviorTreeComponent(), EBTNodeResult::Succeeded);
		ADI_PatrolAIController* PatrolAI = Cast<ADI_PatrolAIController>(Controller);
		PatrolAI->OnDanceEnded();
	}
}
