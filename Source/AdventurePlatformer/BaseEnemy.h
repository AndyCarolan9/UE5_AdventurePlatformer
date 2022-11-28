// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BaseEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ADVENTUREPLATFORMER_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UBehaviorTree> behaviorTree;

public:
	ABaseEnemy();

	UBehaviorTree* GetBehaviorTree() const;	

	virtual void AttackStart();
	virtual void AttackEnd();
};
