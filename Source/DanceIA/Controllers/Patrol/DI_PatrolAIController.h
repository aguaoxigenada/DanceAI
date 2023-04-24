#pragma once

#include "AIModule/Classes/Perception/AIPerceptionTypes.h"
#include "CoreMinimal.h"
#include "Controllers/DI_AIControllerBase.h"
#include "DI_PatrolAIController.generated.h"

class UAISenseConfig_Sight;

UCLASS()
class DANCEIA_API ADI_PatrolAIController : public ADI_AIControllerBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category = AI)
		UAISenseConfig_Sight* SightConfig;

	ADI_PatrolAIController();

	void OnDanceEnded();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	TWeakObjectPtr<AActor> TargetActor; 

	FTimerHandle DanceEnded;

};
