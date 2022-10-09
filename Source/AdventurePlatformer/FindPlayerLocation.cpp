// Fill out your copyright notice in the Description page of Project Settings.


#include "FindPlayerLocation.h"

#include "BaseAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

UFindPlayerLocation::UFindPlayerLocation(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UFindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& ownerComp, uint8* nodeMemory)
{
	if (ACharacter* const player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
	{
		if (ABaseAIController* const controller = Cast<ABaseAIController>(ownerComp.GetAIOwner()))
		{
			FVector const playerLoc = player->GetActorLocation();

			ownerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), playerLoc);

			FinishLatentTask(ownerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}

	return EBTNodeResult::Failed;
}
