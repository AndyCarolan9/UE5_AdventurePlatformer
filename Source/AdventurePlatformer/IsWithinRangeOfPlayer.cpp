// Fill out your copyright notice in the Description page of Project Settings.


#include "IsWithinRangeOfPlayer.h"

#include "BaseAIController.h"
#include "BaseEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UIsWithinRangeOfPlayer::UIsWithinRangeOfPlayer()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Target in Melee Range");
}

void UIsWithinRangeOfPlayer::OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	Super::OnBecomeRelevant(ownerComp, nodeMemory);

	ABaseAIController* const controller = Cast<ABaseAIController>(ownerComp.GetAIOwner());
	ABaseEnemy* const enemy = Cast<ABaseEnemy>(controller->GetPawn());

	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	ownerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),
		enemy->GetDistanceTo(player) <= range);
}
