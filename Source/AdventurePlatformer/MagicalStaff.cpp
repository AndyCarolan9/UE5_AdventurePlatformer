// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicalStaff.h"
#include "MagicProjectile.h"
#include "Components/BoxComponent.h"
#include "BaseEnemy.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMagicalStaff::AMagicalStaff()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	StaffCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Staff Collision"));
	StaffCollision->SetBoxExtent(FVector(10.0f, 30.0f, 10.0f), false);
	StaffCollision->SetCollisionProfileName("NoCollision");

	FAttachmentTransformRules const rules(
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::SnapToTarget,
		EAttachmentRule::KeepWorld,
		false);

	StaffCollision->AttachToComponent(Mesh, rules, "HitBox");
	//StaffCollision->SetRelativeLocation(FVector(0, 0, 0));

	StaffCollision->OnComponentBeginOverlap.AddDynamic(this, &AMagicalStaff::BeginOverlap);
}

void AMagicalStaff::SetCollisionActive(bool bActive)
{
	if (StaffCollision)
	{
		StaffCollision->SetCollisionProfileName(bActive ? "RightFistCollision" : "NoCollision");
		StaffCollision->SetNotifyRigidBodyCollision(bActive);
	}
}

// Called when the game starts or when spawned
void AMagicalStaff::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMagicalStaff::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABaseEnemy* enemy = Cast<ABaseEnemy>(OtherActor);

	if (enemy)
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit %s"), *enemy->GetActorNameOrLabel());
		UGameplayStatics::ApplyDamage(enemy, StaffMeleeDamage, OwnerCharacter->GetController(), this, DamageType);
	}
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

