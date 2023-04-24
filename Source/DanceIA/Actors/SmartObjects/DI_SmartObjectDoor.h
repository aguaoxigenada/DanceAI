#pragma once

#include "CoreMinimal.h"
#include "Actors/SmartObjects/DI_TriggerSmartObject.h"
#include "DI_SmartObjectDoor.generated.h"

class ADI_AICharacterBase;

UCLASS()
class DANCEIA_API ADI_SmartObjectDoor : public ADI_TriggerSmartObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<ADI_AICharacterBase*> AssociatedCharacters;
protected:
	 
	virtual void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
