// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"
#include "Components/BoxComponent.h"
#include "AdventureCharacter.h"
#include "Kismet/GameplayStatics.h"

AMinion::AMinion()
{
	RightFistCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Right Fist Collision"));
	RightFistCollision->SetBoxExtent(FVector(10.0f), false);
	RightFistCollision->SetCollisionProfileName("NoCollision");

	FAttachmentTransformRules const rules(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepWorld,
		false);

	RightFistCollision->AttachToComponent(GetMesh(), rules, "RightHandSocket");
	RightFistCollision->SetRelativeLocation(FVector(0, 0, 0));

	RightFistCollision->OnComponentBeginOverlap.AddDynamic(this, &AMinion::BeginOverlap);
}

void AMinion::AttackStart()
{
	if (RightFistCollision)
	{
		RightFistCollision->SetCollisionProfileName("RightFistCollision");
		RightFistCollision->SetNotifyRigidBodyCollision(true);
	}
}

void AMinion::AttackEnd()
{
	if (RightFistCollision)
	{
		RightFistCollision->SetCollisionProfileName("NoCollision");
		RightFistCollision->SetNotifyRigidBodyCollision(false);
	}
}

void AMinion::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AAdventureCharacter* player = Cast<AAdventureCharacter>(OtherActor))
	{
		UGameplayStatics::ApplyDamage(player, DamageAmount, GetOwner()->GetInstigatorController(), this, DamageType);
	}
}
