// Copyright Epic Games, Inc. All Rights Reserved.

#include "WEEK_2GameMode.h"
#include "WEEK_2Character.h"
#include "UObject/ConstructorHelpers.h"

AWEEK_2GameMode::AWEEK_2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
