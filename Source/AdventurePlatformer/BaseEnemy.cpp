// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

ABaseEnemy::ABaseEnemy()
{

}

UBehaviorTree* ABaseEnemy::GetBehaviorTree() const
{
	return behaviorTree;
}

void ABaseEnemy::AttackStart()
{
}

void ABaseEnemy::AttackEnd()
{
}

void ABaseEnemy::Attack()
{
	FAttackAction* LightAttack = Attacks.FindByPredicate([](FAttackAction inA)
	{
		return inA.Type == EAttackType::Light;
	});

	if (LightAttack)
	{
		PlayAnimMontage(LightAttack->Montage);
	}
}
