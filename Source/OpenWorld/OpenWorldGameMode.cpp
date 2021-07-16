// Copyright Epic Games, Inc. All Rights Reserved.

#include "OpenWorldGameMode.h"
#include "OpenWorldCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOpenWorldGameMode::AOpenWorldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Character/Human/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
