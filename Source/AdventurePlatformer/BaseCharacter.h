// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class ADVENTUREPLATFORMER_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

	static const float MAXHEALTH;

protected:
	UPROPERTY(EditAnywhere, category = "Attack")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(VisibleAnywhere, category = "Health")
	float Health;

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	virtual void ApplyDamage(float damageToApply);

	virtual float GetHealth() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UAnimMontage* GetMontage() const;

private:
	virtual void Attack();
};
