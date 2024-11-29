// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "WEEK_2GameMode.generated.h"

UCLASS(minimalapi)
class AWEEK_2GameMode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

public:
	AWEEK_2GameMode();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Special Settings")
	float EndGameTimer = 10.0f;

	// 定时器句柄
	FTimerHandle GameTimerHandle;

	// 定时器到期时调用的函数
	void OnTimerExpire();
};
