#include "DanceIAGameMode.h"
#include "DanceIACharacter.h"
#include "UObject/ConstructorHelpers.h"

ADanceIAGameMode::ADanceIAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/DanceAI/Blueprints/ThirdPersonCPP/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
