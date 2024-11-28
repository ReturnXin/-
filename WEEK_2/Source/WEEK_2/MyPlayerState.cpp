// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"

void AMyPlayerState::MyAddScore(float ScoreAmount)
{
	bReplicates = true;
	PlayerScore += ScoreAmount;
	// 这里可以加入更多逻辑，例如通知 UI 更新等
}

float AMyPlayerState::MyGetScore() const
{
	return PlayerScore;
}

// void AMyPlayerState::MyOnRepScore()
// {
// 	// 当得分同步到客户端时，可以在这里更新客户端 UI
// }