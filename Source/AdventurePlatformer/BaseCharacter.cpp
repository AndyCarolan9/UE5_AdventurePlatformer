// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

const float ABaseCharacter::MAXHEALTH = 100.0f;

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Health = ABaseCharacter::MAXHEALTH;
}

void ABaseCharacter::ApplyDamage(float damageToApply)
{
	if (damageToApply > Health)
	{
		Health = 0;
	}
	else 
	{
		Health -= damageToApply;
	}
}

float ABaseCharacter::GetHealth() const
{
	return Health;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAnimMontage* ABaseCharacter::GetMontage() const
{
	return Montage;
}

void ABaseCharacter::Attack()
{
}

