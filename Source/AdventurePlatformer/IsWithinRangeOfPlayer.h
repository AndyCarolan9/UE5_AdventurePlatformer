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

	void OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = AI, meta = (AllowPrivateAccess = "true"))
	float range = 25.0f;
};
