// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "FindPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API UFindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UFindPlayerLocation(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory);

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Node Settings", meta = (AllowPrivateAccess = "true"))
	float searchRadius = 150.0f;
};
