// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	FVector ProjectileSpawn;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AMagicProjectile> ProjectileClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void Shoot(FVector CameraLocation, FRotator CameraRotation);
};
