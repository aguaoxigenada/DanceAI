#pragma once

#include "CoreMinimal.h"
#include "Actors/SmartObjects/DI_SmartObjectBase.h"
#include "DI_SplineSmartObject.generated.h"

class USplineComponent;

UCLASS()
class DANCEIA_API ADI_SplineSmartObject : public ADI_SmartObjectBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Patrol AI")
		USplineComponent* SplineComponent = nullptr;

	ADI_SplineSmartObject();

	void FillSplinePoints();
	const TArray<FVector>& GetSplinePoints();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
		TArray<FVector> SplinePoints;
};
