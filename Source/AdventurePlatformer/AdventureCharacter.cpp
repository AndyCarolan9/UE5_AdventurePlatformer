// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureCharacter.h"

#include "Camera/CameraComponent.h"
#include "CoinCollectable.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/MovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "MagicalStaff.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AISense_Sight.h"


// Sets default values
AAdventureCharacter::AAdventureCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	Camera->SetupAttachment(SpringArm);

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AAdventureCharacter::BeginOverlap);

	SetupStimulus();
}

// Called when the game starts or when spawned
void AAdventureCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	if (MagicalStaffClass)
	{
		MagicalStaff = GetWorld()->SpawnActor<AMagicalStaff>(MagicalStaffClass);
		MagicalStaff->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("StaffSocket"));
		MagicalStaff->SetOwnerCharacter(this);
	}
}

// Called every frame
void AAdventureCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AAdventureCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AAdventureCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AAdventureCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRight", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("LightAttack", EInputEvent::IE_Pressed, this, &AAdventureCharacter::LightAttack);
	PlayerInputComponent->BindAction("RangedAttack", EInputEvent::IE_Pressed, this, &AAdventureCharacter::RangedAttack);
	PlayerInputComponent->BindAction("HeavyAttack", EInputEvent::IE_Pressed, this, &AAdventureCharacter::HeavyAttack);
}

void AAdventureCharacter::AttackStart()
{
	if (MagicalStaff)
	{
		MagicalStaff->SetCollisionActive(true);
	}
}

void AAdventureCharacter::AttackEnd()
{
	if (MagicalStaff)
	{
		MagicalStaff->SetCollisionActive(false);
	}
}

void AAdventureCharacter::MoveForward(float val)
{
	FRotator direction = Camera->GetComponentRotation();
	AddMovementInput(UKismetMathLibrary::GetForwardVector(direction), val);
}

void AAdventureCharacter::MoveRight(float val)
{
	FRotator direction = Camera->GetComponentRotation();
	AddMovementInput(UKismetMathLibrary::GetRightVector(direction), val);
}

void AAdventureCharacter::LightAttack()
{
	FAttackAction* action = PlayAttack(EAttackType::Light);

	if (action)
	{
		MagicalStaff->SetDamageType(action->DamageType);
		MagicalStaff->SetMeleeDamage(action->Damage);
	}
}

void AAdventureCharacter::RangedAttack()
{
	PlayAttack(EAttackType::Ranged);
}

void AAdventureCharacter::HeavyAttack()
{

}

FAttackAction* AAdventureCharacter::PlayAttack(EAttackType type)
{
	FAttackAction* Attack = Attacks.FindByPredicate([type](FAttackAction inA)
	{
		return inA.Type == type;
	});

	if (MagicalStaff && Attack)
	{
		PlayAnimMontage(Attack->Montage);
	}

	return Attack;
}

void AAdventureCharacter::FireProjectile()
{
	if (MagicalStaff)
	{
		MagicalStaff->Shoot(GetActorRotation());
	}
}

void AAdventureCharacter::SetupStimulus()
{
	stimulus = CreateDefaultSubobject<UAIPerceptionStimuliSourceComponent>(TEXT("stimulus"));
	stimulus->RegisterForSense(TSubclassOf<UAISense_Sight>());
	stimulus->RegisterWithPerceptionSystem();
}

void AAdventureCharacter::BeginOverlap
(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && dynamic_cast<ACoinCollectable*>(OtherActor))
	{
		coinsCollected++;
	}
}