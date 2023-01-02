// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Components/HealthComponent.h"
#include "GameFramework/PawnMovementComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health Comp"));
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (HealthComponent)
	{
		HealthComponent->OnHealthChanged.AddDynamic(this, &ABaseCharacter::OnHealthChanged);
	}
}

void ABaseCharacter::OnHealthChanged(UHealthComponent* HealthComp, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Health <= 0 && !HealthComponent->IsDead())
	{
		GetMovementComponent()->StopMovementImmediately();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		DetachFromControllerPendingDestroy();
		SetLifeSpan(5.0f);
	}
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::AttackStart()
{
}

void ABaseCharacter::AttackEnd()
{
}

void ABaseCharacter::LightAttack()
{
}

void ABaseCharacter::RangedAttack()
{

}

void ABaseCharacter::HeavyAttack()
{

}

