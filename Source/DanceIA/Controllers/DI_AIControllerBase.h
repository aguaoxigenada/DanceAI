#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DI_AIControllerBase.generated.h"

class ADI_AICharacterBase;
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS()
class DANCEIA_API ADI_AIControllerBase : public AAIController
{
	GENERATED_BODY()

public:
	ADI_AIControllerBase();

	void SetSmartObjectTree();
	UBlackboardComponent* GetBlackboardComponent() const;
	UBehaviorTreeComponent* GetBehaviorTreeComponent() const;
	
protected:
	UPROPERTY()
		UBehaviorTreeComponent* BehaviorTreeComponent = nullptr;

	UPROPERTY()
		UBlackboardComponent* BlackboardComponent = nullptr;

	virtual void OnPossess(APawn* InPawn) override;
	virtual void BeginPlay() override;

	ADI_AICharacterBase* Dancer = nullptr;

};
