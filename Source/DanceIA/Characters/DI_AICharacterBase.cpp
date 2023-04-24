#include "Characters/DI_AICharacterBase.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "BehaviorTree/BehaviorTree.h"

UBehaviorTree* ADI_AICharacterBase::GetBehaviorTree() const
{
	return BehaviorTree;
}

ADI_SmartObjectBase* ADI_AICharacterBase::GetCurrentSmartObject() const
{
	return CurrentSmartObject;
}

void ADI_AICharacterBase::SetCurrentSmartObject(ADI_SmartObjectBase* SmartObject)
{
	LastSmartObject = GetCurrentSmartObject();
	CurrentSmartObject = SmartObject;
}
