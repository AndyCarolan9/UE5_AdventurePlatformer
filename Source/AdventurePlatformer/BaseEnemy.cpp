// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

ABaseEnemy::ABaseEnemy()
{

}

UBehaviorTree* ABaseEnemy::GetBehaviorTree() const
{
	return behaviorTree;
}

void ABaseEnemy::LightAttack()
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
