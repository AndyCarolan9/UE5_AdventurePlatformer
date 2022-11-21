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
