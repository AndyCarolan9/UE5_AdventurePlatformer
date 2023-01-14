// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "IsWithinRangeOfPlayer.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API UIsWithinRangeOfPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UIsWithinRangeOfPlayer();

	void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
	float range = 25.0f;
};
