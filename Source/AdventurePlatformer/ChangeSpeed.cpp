// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeSpeed.h"

#include "AIController.h"
#include "BaseEnemy.h"
#include "GameFramework/CharacterMovementComponent.h"

UChangeSpeed::UChangeSpeed()
{
	bNotifyBecomeRelevant = true;

	NodeName = TEXT("Change Speed");
}

void UChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	Super::OnBecomeRelevant(ownerComp, nodeMemory);

	if (auto const controller = ownerComp.GetAIOwner())
	{
		if (auto const npc = Cast<ABaseEnemy>(controller->GetPawn()))
		{
			npc->GetCharacterMovement()->MaxWalkSpeed = speed;
		}
	}
}

FString UChangeSpeed::GetStaticServiceDescription() const
{
	return FString("Changes the Enemy's Speed");
}
