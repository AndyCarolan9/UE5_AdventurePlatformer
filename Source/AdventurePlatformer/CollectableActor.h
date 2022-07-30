// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableActor.generated.h"

UCLASS()
class ADVENTUREPLATFORMER_API ACollectableActor : public AActor
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* Capsule;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, category = "Rotation")
	FRotator RotationVelocity = FRotator(0.f, 0.f, 90.f);

public:	
	// Sets default values for this actor's properties
	ACollectableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
