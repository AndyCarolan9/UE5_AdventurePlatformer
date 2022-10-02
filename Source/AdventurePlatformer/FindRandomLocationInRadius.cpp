// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocationInRadius.h"

#include "BaseAIController.h"
#include "BaseEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"

UFindRandomLocationInRadius::UFindRandomLocationInRadius(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Random Location In Radius");
}

EBTNodeResult::Type UFindRandomLocationInRadius::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	if (auto const controller = Cast<ABaseAIController>(ownerComp.GetAIOwner()))
	{
		if (auto const npcPawn = Cast<ABaseEnemy>(controller->GetPawn()))
		{
			FVector const origin = npcPawn->GetActorLocation();

			if (UNavigationSystemV1* const navSys = UNavigationSystemV1::GetCurrent(GetWorld()))
			{
				FNavLocation loc;

				if (navSys->GetRandomPointInNavigableRadius(origin, searchRadius, loc))
				{
					ownerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), loc.Location);

					FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
					return EBTNodeResult::Succeeded;
				}
			}
		}
	}

	return EBTNodeResult::Failed;
}
