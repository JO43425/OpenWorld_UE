// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskNode_FindPatrolPos.h"
#include "OWAIController.h"
#include "OWCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NavigationSystem.h"


UBTTaskNode_FindPatrolPos::UBTTaskNode_FindPatrolPos()
{
}

EBTNodeResult::Type UBTTaskNode_FindPatrolPos::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
		return EBTNodeResult::Failed;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetNavigationSystem(ControllingPawn->GetWorld());
	if (nullptr == NavSystem)
	{
		return EBTNodeResult::Failed;
	}

	FVector Origin = OwnerComp.GetBlackboardComponent()->GetValueAsVector(AOWAIController::HomePosKey);
	FNavLocation NextPatrol;

	if (NavSystem->GetRandomPointInNavigableRadius(Origin, 3000.0f, NextPatrol))
	{
		ChangeMoveState(Cast<AOWCharacter>(ControllingPawn));
		OwnerComp.GetBlackboardComponent()->SetValueAsVector(AOWAIController::PatrolPosKey, NextPatrol.Location);
		return EBTNodeResult::Succeeded;
	}

	return EBTNodeResult::Failed;
}

void UBTTaskNode_FindPatrolPos::ChangeMoveState(class AOWCharacter* ControllingPawn)
{
	GAME_CHECK(ControllingPawn);
	int32 value = FMath::RandRange(0, 3);
	ControllingPawn->ResetIdle();

	if (value == 1)
	{
		ControllingPawn->Sprint();
	}
	else if (value == 2)
	{
		ControllingPawn->ToggleCrouch();
	}
	else if (value == 3)
	{
		ControllingPawn->ToggleRun();
	}
}
