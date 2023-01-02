// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackNotifyState.h"

#include "BaseEnemy.h"

void UAttackNotifyState::NotifyBegin(USkeletalMeshComponent* const mesh, UAnimSequenceBase* const animation, float const total_duration)
{
	if (mesh && mesh->GetOwner())
	{
		if (ABaseCharacter* const enemy = Cast<ABaseCharacter>(mesh->GetOwner()))
		{
			enemy->AttackStart();
		}
	}
}

void UAttackNotifyState::NotifyEnd(USkeletalMeshComponent* const mesh, UAnimSequenceBase* const animation)
{
	if (mesh && mesh->GetOwner())
	{
		if (ABaseCharacter* const enemy = Cast<ABaseCharacter>(mesh->GetOwner()))
		{
			enemy->AttackEnd();
		}
	}
}
