// Fill out your copyright notice in the Description page of Project Settings.


#include "HitTarget.h"

#include "TP_WeaponComponent.h"
#include "Components/BoxComponent.h"
#include "WEEK_2Projectile.h"
#include "WEEK_2Character.h"

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
		if (AActor* Projectile = Cast<AWEEK_2Projectile>(OtherActor))
		{
			HitCount++;
			if (HitCount == 1)
			{
				FVector currentScale = MyComp->GetComponentScale();
				MyComp->SetRelativeScale3D(currentScale * Scale);
			}
			else if (HitCount == 2)
			{
				if (const AWEEK_2Character* Character = Cast<AWEEK_2Character>(Projectile->GetOwner()))
				{
					if (AMyPlayerState* PS = Cast<AMyPlayerState>(Character->GetPlayerState()))
					{
						if (IsImportant)
						{
							PS->MyAddScore(Score * 2);
						}
						else
							PS->MyAddScore(Score);
					}
				}

				// 销毁
				this->Destroy();
			}
		}
	}
}
