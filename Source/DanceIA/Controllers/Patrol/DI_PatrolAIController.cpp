#include "Controllers/Patrol/DI_PatrolAIController.h"
#include "DanceIAGameMode.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "Characters/DI_AICharacterBase.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTreeComponent.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "AIModule/Classes/Perception/AIPerceptionComponent.h"
#include "AIModule/Classes/Perception/AIPerceptionSystem.h"
#include "AIModule/Classes/Perception/AISenseConfig_Sight.h"

ADI_PatrolAIController::ADI_PatrolAIController() : Super()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	SightConfig->SightRadius = 150.f;
	SightConfig->LoseSightRadius = SightConfig->SightRadius + 20.f;
	SightConfig->PeripheralVisionAngleDegrees = 45.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	PerceptionComponent->ConfigureSense(*SightConfig);
	PerceptionComponent->SetDominantSense(SightConfig->GetSenseImplementation());
}

void ADI_PatrolAIController::BeginPlay()
{
	Super::BeginPlay();  

	Dancer = Cast<ADI_AICharacterBase>(GetPawn());
	PerceptionComponent->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &ADI_PatrolAIController::OnTargetPerceptionUpdated);
}

void ADI_PatrolAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (UAIPerceptionSystem::GetSenseClassForStimulus(this, Stimulus) == UAISense_Sight::StaticClass())
	{
		if (Stimulus.WasSuccessfullySensed() && Actor->ActorHasTag(TEXT("Dance")))
		{
			TargetActor = Actor;
			BehaviorTreeComponent->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>("TargetActor", TargetActor.Get());
			ADanceIAGameMode* DanceGameMode = Cast<ADanceIAGameMode>(GetWorld()->GetAuthGameMode());
			DanceGameMode->StartMusic();
		}
	}
}

void ADI_PatrolAIController::OnDanceEnded()
{
	BehaviorTreeComponent->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>("bDancePointDetected", false);
	
	Dancer->SetCurrentSmartObject(Dancer->LastSmartObject);

	TargetActor = nullptr;
	BehaviorTreeComponent->GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>("TargetActor", nullptr);

	ADI_SmartObjectBase* SplineSmartObject = Dancer->GetCurrentSmartObject();
	if (SplineSmartObject)
	{
		FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, SplineSmartObject->GetBehaviorTree());
	}
}


