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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<class UBoxComponent> RightFistCollision;

	UPROPERTY(EditAnywhere, Category = "Attack")
	float DamageAmount;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<class UDamageType> DamageType;

	UFUNCTION()
	void BeginOverlap
		(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
};
