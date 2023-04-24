#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_ExecuteSmartObjectInfo.generated.h"

class ADI_SmartObjectBase;
class ADI_AIControllerBase;

UCLASS()
class DANCEIA_API UBTTask_ExecuteSmartObjectInfo : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	
	UBTTask_ExecuteSmartObjectInfo();

protected:
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	UPROPERTY()
		ADI_AIControllerBase* Controller = nullptr;

	bool bCanFinish = false;
	FTimerHandle AnimationTimer;
	void OnAnimationTimer();
	
	ADI_SmartObjectBase* SmartObject = nullptr;

};
