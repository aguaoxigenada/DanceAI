#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DI_SmartObjectBase.generated.h"

class UBillboardComponent;
class UArrowComponent;
class UBehaviorTree;
class UAnimMontage;

USTRUCT(BlueprintType)
struct FTC_SmartObjectInformation
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		UAnimMontage* AnimToPlay = nullptr;

};

UCLASS()
class DANCEIA_API ADI_SmartObjectBase : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UBillboardComponent* BillboardComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* ArrowComponent = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FTC_SmartObjectInformation SmartObjectInformation;

	ADI_SmartObjectBase();
	UBehaviorTree* GetBehaviorTree() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = AI)
		UBehaviorTree* BehaviorTree;

};
