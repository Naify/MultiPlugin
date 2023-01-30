// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPluginGameMode.h"
#include "MultiPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiPluginGameMode::AMultiPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
