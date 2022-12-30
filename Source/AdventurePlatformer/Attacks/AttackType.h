// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttackType.generated.h"

UENUM(BlueprintType)
enum EAttackType
{
	Light,
	Ranged,
	Heavy,
};


USTRUCT(BlueprintType)
struct FAttackAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TEnumAsByte<EAttackType> Type;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UAnimMontage> Montage;

	UPROPERTY(EditDefaultsOnly)
	float Damage;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UDamageType> DamageType;
};
