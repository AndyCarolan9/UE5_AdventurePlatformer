// Fill out your copyright notice in the Description page of Project Settings.


#include "AdventureCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/MovementComponent.h"

// Sets default values
AAdventureCharacter::AAdventureCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AAdventureCharacter::BeginPlay()
{
	Super::BeginPlay();
	
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

}

void AAdventureCharacter::MoveForward(float val)
{
	FRotator rotation = FRotator(0, 0, GetControlRotation().Yaw);
	
	AddMovementInput(GetActorForwardVector(), val);
}

void AAdventureCharacter::MoveRight(float val)
{
	FRotator rotation = FRotator(0, 0, GetControlRotation().Yaw);
	AddMovementInput(UKismetMathLibrary::GetRightVector(rotation), val);
}