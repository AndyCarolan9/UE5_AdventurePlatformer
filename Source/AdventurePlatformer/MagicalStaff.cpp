// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicalStaff.h"
#include "MagicProjectile.h"

// Sets default values
AMagicalStaff::AMagicalStaff()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMagicalStaff::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMagicalStaff::Shoot(FRotator CameraRotation)
{
	if (ProjectileClass)
	{
		FVector SpawnLoc = Mesh->GetSocketLocation(TEXT("Spawn Point"));

		FRotator SpawnRotation = CameraRotation;

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		AMagicProjectile* Projectile = GetWorld()->SpawnActor<AMagicProjectile>(ProjectileClass, SpawnLoc, SpawnRotation, SpawnParams);

		if (Projectile)
		{
			FVector LaunchDirection = SpawnRotation.Vector();
			Projectile->FireInDirection(LaunchDirection);
		}
	}
}

