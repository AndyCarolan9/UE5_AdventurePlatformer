// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAttackPlayer.h"
#include "../BaseCharacter.h"
#include "../BaseAIController.h"
#include "../BaseEnemy.h"
#include "Components/SkeletalMeshComponent.h"
#include "Animation/AnimMontage.h"
#include "Animation/AnimInstance.h"

UMeleeAttackPlayer::UMeleeAttackPlayer(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Melee Attack");
}

EBTNodeResult::Type UMeleeAttackPlayer::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	ABaseAIController* const Controller = Cast<ABaseAIController>(ownerComp.GetAIOwner());
	ABaseEnemy* const Enemy = Cast<ABaseEnemy>(Controller->GetPawn());

	if (Enemy)
	{
		if (IsMontageFinished(Enemy))
		{
			Enemy->MeleeAttack();
		}
	}
	
	FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

bool UMeleeAttackPlayer::IsMontageFinished(ABaseCharacter* const enemy)
{
	return enemy->GetMesh()->GetAnimInstance()->Montage_GetIsStopped(enemy->GetMontage());
}
