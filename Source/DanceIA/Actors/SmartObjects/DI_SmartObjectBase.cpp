#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "AIModule/Classes/BehaviorTree/BehaviorTree.h"
#include "Components/ArrowComponent.h"
#include "Components/BillboardComponent.h"

ADI_SmartObjectBase::ADI_SmartObjectBase()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	BillboardComponent = CreateDefaultSubobject<UBillboardComponent>(TEXT("BillboardComponent"));
	BillboardComponent->SetupAttachment(RootComponent);

	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);
}

UBehaviorTree* ADI_SmartObjectBase::GetBehaviorTree() const
{
	return BehaviorTree;
}