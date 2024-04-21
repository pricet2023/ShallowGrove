// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShallowGroveGameMode.h"
#include "ShallowGroveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShallowGroveGameMode::AShallowGroveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
