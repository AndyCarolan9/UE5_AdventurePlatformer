// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	DefaultHealth = 100;
}

float UHealthComponent::GetHealth() const
{
	return Health;
}

bool UHealthComponent::IsDead() const
{
	return bIsDead;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	
	AActor* MyOwner = GetOwner();

	if (MyOwner)
	{
		MyOwner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
}

void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0 || bIsDead)
	{
		return;
	}

	Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);

	UE_LOG(LogTemp, Warning, TEXT("Health: %s"), *FString::SanitizeFloat(Health));

	bIsDead = Health == 0.0f;

	OnHealthChanged.Broadcast(this, DamageType, InstigatedBy, DamageCauser);
}
