#pragma once

#include "CoreMinimal.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "DI_TriggerSmartObject.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class DANCEIA_API ADI_TriggerSmartObject : public ADI_SmartObjectBase
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(EditAnywhere)
		USphereComponent* SphereComponent = nullptr;

	ADI_TriggerSmartObject();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
		virtual void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
