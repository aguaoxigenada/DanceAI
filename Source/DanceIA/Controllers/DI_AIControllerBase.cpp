#include "Controllers/DI_AIControllerBase.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/DI_AICharacterBase.h"


ADI_AIControllerBase::ADI_AIControllerBase()
{
	BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behavior Tree Component"));
	BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard Component"));
}


void ADI_AIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	SetSmartObjectTree();
}

UBlackboardComponent* ADI_AIControllerBase::GetBlackboardComponent() const
{
	return BlackboardComponent;
}

UBehaviorTreeComponent* ADI_AIControllerBase::GetBehaviorTreeComponent() const
{
	return BehaviorTreeComponent;
}

void ADI_AIControllerBase::SetSmartObjectTree()
{
	ADI_AICharacterBase* CharacterBase = Cast<ADI_AICharacterBase>(GetPawn());
	if (!CharacterBase)
		return;
	
	ADI_SmartObjectBase* SmartObject = CharacterBase->GetCurrentSmartObject();
	if (SmartObject)
	{
		FGameplayTag SubTag;
		BehaviorTreeComponent->SetDynamicSubtree(SubTag, SmartObject->GetBehaviorTree());
	}
}

void ADI_AIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	ADI_AICharacterBase* CharacterBase = Cast<ADI_AICharacterBase>(InPawn);
	UBehaviorTree* CharacterBehaviorTree = CharacterBase ? CharacterBase->GetBehaviorTree() : nullptr;
	if (CharacterBehaviorTree)
	{
		BlackboardComponent->InitializeBlackboard(*CharacterBehaviorTree->BlackboardAsset);
		BehaviorTreeComponent->StartTree(*CharacterBehaviorTree);
	}
}


