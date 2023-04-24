#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DanceIAGameMode.generated.h"

UCLASS(minimalapi)
class ADanceIAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
		void StartMusic();

	ADanceIAGameMode();
};



