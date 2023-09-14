// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5MultPluginGameMode.h"
#include "UE5MultPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5MultPluginGameMode::AUE5MultPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
