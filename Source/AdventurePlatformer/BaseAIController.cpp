// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"
#include "BaseEnemy.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"

ABaseAIController::ABaseAIController(FObjectInitializer const& objectInitializer)
{
	SetupPerceptionSystem();
}

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	if (auto const Enemy = Cast<ABaseEnemy>(GetPawn()))
	{
		if (auto const tree = Enemy->GetBehaviorTree())
		{
			UseBlackboard(tree->BlackboardAsset, blackboardComponent);
		}
	}
}

void ABaseAIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);

	if (auto const Enemy = Cast<ABaseEnemy>(pawn))
	{
		if (auto const tree = Enemy->GetBehaviorTree())
		{
			RunBehaviorTree(tree);
		}
	}
}

void ABaseAIController::OnSenseUpdated(TArray<AActor*> const& updatedActors)
{
}

void ABaseAIController::SetupPerceptionSystem()
{
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

	if (sightConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		sightConfig->SightRadius = 500.0f;
		sightConfig->LoseSightRadius = sightConfig->SightRadius + 25.0f;
		sightConfig->PeripheralVisionAngleDegrees = 90.0f;
		sightConfig->SetMaxAge(5.0f);
		sightConfig->AutoSuccessRangeFromLastSeenLocation = 520.0f;
		sightConfig->DetectionByAffiliation.bDetectEnemies = true;
		sightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		sightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->SetDominantSense(*sightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this, &ABaseAIController::OnSenseUpdated);
		GetPerceptionComponent()->ConfigureSense(*sightConfig);
	}
}
