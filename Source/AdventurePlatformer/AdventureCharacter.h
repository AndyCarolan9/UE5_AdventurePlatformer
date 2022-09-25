// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AdventureCharacter.generated.h"

UCLASS()
class ADVENTUREPLATFORMER_API AAdventureCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, category = "Collectables")
	int coinsCollected;

	UPROPERTY(EditDefaultsOnly, category = "Magical Staff")
	TSubclassOf<class AMagicalStaff> MagicalStaffClass;

	UPROPERTY()
	class AMagicalStaff* MagicalStaff;

	UPROPERTY(EditAnywhere, category = "Attack")
	UAnimMontage* Montage;
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Direction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float Speed;
public:
	// Sets default values for this character's properties
	AAdventureCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void BeginOverlap
			(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(float val);
	void MoveRight(float val);

	void Attack();

	UFUNCTION(BlueprintCallable, Category = "Player Actions")
	void FireProjectile();
};
