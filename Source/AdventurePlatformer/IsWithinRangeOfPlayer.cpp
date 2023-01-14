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
	/*Super::OnBecomeRelevant(ownerComp, nodeMemory);

	ABaseAIController* const controller = Cast<ABaseAIController>(ownerComp.GetAIOwner());
	ABaseEnemy* const enemy = Cast<ABaseEnemy>(controller->GetPawn());

	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (player)
	{
		ownerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),
			enemy->GetDistanceTo(player) <= range);
	}
	else
	{
		ownerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
	}*/
}

void UIsWithinRangeOfPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	ABaseAIController* const controller = Cast<ABaseAIController>(OwnerComp.GetAIOwner());
	ABaseEnemy* const enemy = Cast<ABaseEnemy>(controller->GetPawn());

	ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	if (player)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(),
			enemy->GetDistanceTo(player) <= range);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
	}
}
