// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "ChangeSpeed.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API UChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UChangeSpeed();

	void OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory) override;

protected:
	FString GetStaticServiceDescription() const override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	float speed = 600.0f;
};
