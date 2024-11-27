// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitTarget.generated.h"

UCLASS()
class WEEK_2_API AHitTarget : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHitTarget();

	float Score = 1.f;
	float Scale = 0.5f;
	int HitCount = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* MyComp;

	UFUNCTION()
	void OnCompHit(UPrimitiveComponent* HitComp,
	               AActor* OtherActor,
	               UPrimitiveComponent* OtherComp,
	               FVector NormalImpulse,
	               const FHitResult& Hit);
};
