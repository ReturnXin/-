// Copyright Epic Games, Inc. All Rights Reserved.

#include "WEEK_2GameMode.h"
#include "WEEK_2Character.h"
#include "UObject/ConstructorHelpers.h"
#include "MyPlayerState.h"

AWEEK_2GameMode::AWEEK_2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// 自定义的PlayerState与Character进行绑定
	PlayerStateClass = AMyPlayerState::StaticClass();
}

void AWEEK_2GameMode::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Begin Play"));
	Super::BeginPlay();

	if (GetWorld())
	{
		GetWorldTimerManager().SetTimer(GameTimerHandle, this, &AWEEK_2GameMode::OnTimerExpire, EndGameTimer, false);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("World is not valid in BeginPlay."));
	}
}

void AWEEK_2GameMode::OnTimerExpire()
{
	UE_LOG(LogTemp, Warning, TEXT(" =====End Game======="));
	// 结束所有玩家的游戏
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		if (APlayerController* PlayerController = It->Get())
		{
			if (AWEEK_2Character* Character = Cast<AWEEK_2Character>(PlayerController->GetCharacter()))
			{
				if (AMyPlayerState* PS = Cast<AMyPlayerState>(Character->GetPlayerState()))
				{
					UE_LOG(LogTemp, Warning, TEXT("The Score is %f"), PS->MyGetScore());
				}
			}
			PlayerController->ConsoleCommand("quit");
		}
	}
}
