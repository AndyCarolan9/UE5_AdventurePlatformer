// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAIController.h"

#include "BaseEnemy.h"
#include "BehaviorTree/BlackboardComponent.h" 
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"

ABaseAIController::ABaseAIController(FObjectInitializer const& objectInitializer)
{
}

void ABaseAIController::BeginPlay()
{
	Super::BeginPlay();

	/*if (auto const Enemy = Cast<ABaseEnemy>(GetPawn()))
	{
		if (auto const tree = Enemy->GetBehaviorTree())
		{
			UseBlackboard(tree->BlackboardAsset, blackboardComponent);
		}
	}*/
}

void ABaseAIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);

	//if (auto const Enemy = Cast<ABaseEnemy>(pawn))
	//{
	//	if (auto const tree = Enemy->GetBehaviorTree())
	//	{
	//		RunBehaviorTree(tree);
	//	}
	//}
}