// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Attacks/AttackType.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ADVENTUREPLATFORMER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	static const float MAXHEALTH;

protected:
	UPROPERTY(EditAnywhere, category = "Attack")
	TArray<FAttackAction> Attacks;

	UPROPERTY(VisibleAnywhere, Category = "Components");
	TObjectPtr<class UHealthComponent> HealthComponent;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHealthChanged(class UHealthComponent* HealthComp, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void AttackStart();
	virtual void AttackEnd();

private:
	virtual void LightAttack();
	virtual void RangedAttack();
	virtual void HeavyAttack();
};
