#include "Actors/SmartObjects/DI_SmartObjectDoor.h"
#include "DanceIACharacter.h"
#include "AIModule/Classes/BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Controllers/DI_AIControllerBase.h"
#include "Characters/DI_AICharacterBase.h"


void ADI_SmartObjectDoor::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ADanceIACharacter* Character = Cast<ADanceIACharacter>(OtherActor))
	{
		for (ADI_AICharacterBase* AssociatedCharacter : AssociatedCharacters)
		{
			ADI_AIControllerBase* CharacterController = Cast<ADI_AIControllerBase>(AssociatedCharacter->GetController());
			UBlackboardComponent* BlackboardComponent = CharacterController ? CharacterController->GetBlackboardComponent() : nullptr;
			if (BlackboardComponent)
			{
				AssociatedCharacter->SetCurrentSmartObject(this);
				BlackboardComponent->SetValue<UBlackboardKeyType_Bool>("CanRunEQS", true);
			}
		}

	}

}