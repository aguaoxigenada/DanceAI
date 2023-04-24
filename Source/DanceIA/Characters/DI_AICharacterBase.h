#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DI_AICharacterBase.generated.h"

class UBehaviorTree;
class ADI_SmartObjectBase;

UCLASS()
class DANCEIA_API ADI_AICharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	UBehaviorTree* GetBehaviorTree() const;
	ADI_SmartObjectBase* GetCurrentSmartObject() const;
	void SetCurrentSmartObject(ADI_SmartObjectBase* SmartObject);

	UPROPERTY(EditAnywhere, Category = AI)
		ADI_SmartObjectBase* LastSmartObject = nullptr;

	float AnimDuration = 0.f;


protected:
	UPROPERTY(EditAnywhere, Category = AI)
		UBehaviorTree* BehaviorTree = nullptr;

	UPROPERTY(EditAnywhere, Category = AI)
		ADI_SmartObjectBase* CurrentSmartObject = nullptr;


};
