// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableActor.h"
#include "AdventureCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACollectableActor::ACollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Trigger Capsule"));
	Capsule->SetCollisionProfileName(TEXT("Trigger"));
	Capsule->SetupAttachment(RootComponent);

	Capsule->OnComponentBeginOverlap.AddDynamic(this, &ACollectableActor::OnOverlapBegin);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Capsule);
}

// Called when the game starts or when spawned
void ACollectableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

void ACollectableActor::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && dynamic_cast<AAdventureCharacter*>(OtherActor))
	{
		Destroy();
	}
}

