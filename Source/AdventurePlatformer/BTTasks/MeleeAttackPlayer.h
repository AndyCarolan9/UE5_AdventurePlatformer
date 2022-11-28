// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "MeleeAttackPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API UMeleeAttackPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UMeleeAttackPlayer(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory);

private:
	bool IsMontageFinished(class ABaseCharacter* const enemy);
};
