// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseEnemy.h"
#include "Minion.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API AMinion : public ABaseEnemy
{
	GENERATED_BODY()
	
public:
	AMinion();

	void AttackStart() override;
	void AttackEnd() override;

	void MeleeAttack() override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<class UBoxComponent> RightFistCollision;
};
