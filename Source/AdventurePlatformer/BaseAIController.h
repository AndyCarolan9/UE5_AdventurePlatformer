// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionTypes.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	UPROPERTY()
	UBlackboardComponent* blackboardComponent;

	TObjectPtr<class UAISenseConfig_Sight> sightConfig;

	UFUNCTION()
	virtual void OnSenseUpdated(TArray<AActor*> const& updatedActors);

	virtual void SetupPerceptionSystem();

public:
	ABaseAIController(FObjectInitializer const& objectInitializer);

	void BeginPlay() override;

	void OnPossess(APawn* const pawn) override;
};
