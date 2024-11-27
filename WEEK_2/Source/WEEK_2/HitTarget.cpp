// Fill out your copyright notice in the Description page of Project Settings.


#include "HitTarget.h"

#include "Components/BoxComponent.h"
#include "WEEK_2Projectile.h"

// Sets default values
AHitTarget::AHitTarget()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);

	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AHitTarget::OnCompHit);

	RootComponent = MyComp;
}

// Called when the game starts or when spawned
void AHitTarget::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHitTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHitTarget::OnCompHit(UPrimitiveComponent* HitComp,
                                AActor* OtherActor,
                                UPrimitiveComponent* OtherComp,
                                FVector NormalImpulse,
                                const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		// if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("I Hit: %s"), *OtherActor->GetName()));
		AActor* Projecttile = Cast<AWEEK_2Projectile>(OtherActor);
		if (Projecttile != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("The Actor's name is %s"), *OtherActor->GetName());
			HitCount++;
			if (HitCount == 1)
			{
				FVector currentScale = MyComp->GetComponentScale();
				MyComp->SetRelativeScale3D(currentScale * Scale);
				// TODO: add Score
			}
			else if (HitCount == 2)
			{
				this->Destroy();
			}
		}
	}
}
