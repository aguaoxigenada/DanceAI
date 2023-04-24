#include "BehaviorTree/Tasks/BTTask_GetPathtPoint.h"
#include "Actors/SmartObjects/DI_SplineSmartObject.h"
#include "AIModule/Classes/AIController.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Characters/Patrol/DI_PatrolAICharacter.h"


UBTTask_GetPathtPoint::UBTTask_GetPathtPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	NodeName = "Get Path Point";
	bCreateNodeInstance = true;
}

EBTNodeResult::Type UBTTask_GetPathtPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* OwnerBlackboard = OwnerComp.GetBlackboardComponent();
	AAIController* OwnerController = OwnerComp.GetAIOwner();

	if (!OwnerBlackboard || !OwnerController) 
	{
		return EBTNodeResult::Failed;
	}

	ADI_PatrolAICharacter* PatrolCharacter = Cast<ADI_PatrolAICharacter>(OwnerController->GetPawn());
	if (!PatrolCharacter)
	{
		return EBTNodeResult::Failed;
	}

	ADI_SplineSmartObject* SplineSmartObject = Cast<ADI_SplineSmartObject>(PatrolCharacter->GetCurrentSmartObject());
	
	if (!SplineSmartObject)
	{
		return EBTNodeResult::Failed;
	}

	const TArray<FVector>& SplinePoints = SplineSmartObject->GetSplinePoints();
	if (CurrentSplineIndex > SplinePoints.Num())
	{
		return EBTNodeResult::Failed;
	}

	OwnerBlackboard->SetValue<UBlackboardKeyType_Vector>("MoveToLocation", SplinePoints[CurrentSplineIndex]);
		
	if (CurrentSplineIndex < SplinePoints.Num() - 1)
	{
		++CurrentSplineIndex;
		return EBTNodeResult::Succeeded;
	}
		
	// Empieza de vuelta
	CurrentSplineIndex = 0;
	return EBTNodeResult::Succeeded;
	
}

