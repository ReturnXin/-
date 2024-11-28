// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class WEEK_2_API AMyPlayerState : public APlayerState
{
	GENERATED_BODY()

private:
	// 玩家得分
	UPROPERTY()
	float PlayerScore;

	// 当得分更新时调用的函数
	// UFUNCTION()
	// void MyOnRepScore();

public:
	// 设置和获取得分的函数
	UFUNCTION(BlueprintCallable, Category = "Score")
	void MyAddScore(float ScoreAmount);

	UFUNCTION(BlueprintCallable, Category = "Score")
	float MyGetScore() const;
};
