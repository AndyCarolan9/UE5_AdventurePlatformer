// Fill out your copyright notice in the Description page of Project Settings.


#include "Minion.h"
#include "Components/BoxComponent.h"

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
