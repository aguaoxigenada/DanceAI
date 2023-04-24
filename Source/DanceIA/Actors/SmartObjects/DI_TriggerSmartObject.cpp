#include "Actors/SmartObjects/DI_TriggerSmartObject.h"
#include "Characters/DI_AICharacterBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Controllers/DI_AIControllerBase.h"

ADI_TriggerSmartObject::ADI_TriggerSmartObject()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMeshComponent->SetupAttachment(RootComponent);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(RootComponent);
}

void ADI_TriggerSmartObject::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddUniqueDynamic(this, &ADI_TriggerSmartObject::OnComponentBeginOverlap);
}

void ADI_TriggerSmartObject::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADI_AICharacterBase* CharacterBase = Cast<ADI_AICharacterBase>(OtherActor);

	if (CharacterBase)
	{
		ADI_AIControllerBase* ControllerBase = Cast<ADI_AIControllerBase>(CharacterBase->GetController());
		if (ControllerBase)
		{
			CharacterBase->SetCurrentSmartObject(this);
			ControllerBase->SetSmartObjectTree();
		}
	}
}
