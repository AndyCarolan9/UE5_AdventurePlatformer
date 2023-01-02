// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AdventureCharacter.h"
#include "MagicalStaff.generated.h"

UCLASS()
class ADVENTUREPLATFORMER_API AMagicalStaff : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

public:
	// Sets default values for this actor's properties
	AMagicalStaff();

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMagicProjectile> ProjectileClass;

	void SetMeleeDamage(float value) { StaffMeleeDamage = value; }

	void SetDamageType(TSubclassOf<class UDamageType> value) { DamageType = value; }

	void SetOwnerCharacter(ABaseCharacter* value) { OwnerCharacter = value; }

	void SetCollisionActive(bool bActive);

protected:
	float StaffMeleeDamage;

	ABaseCharacter* OwnerCharacter;

	TSubclassOf<class UDamageType> DamageType;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collision")
	TObjectPtr<class UBoxComponent> StaffCollision;

	UFUNCTION()
	void BeginOverlap
		(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

public:
	void Shoot(FRotator CameraRotation);
};
