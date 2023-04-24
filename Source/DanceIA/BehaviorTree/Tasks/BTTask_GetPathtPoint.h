#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_GetPathtPoint.generated.h"


UCLASS()
class DANCEIA_API UBTTask_GetPathtPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_GetPathtPoint(const FObjectInitializer& ObjectInitializer);

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	int32 CurrentSplineIndex = 0; 

	
};
