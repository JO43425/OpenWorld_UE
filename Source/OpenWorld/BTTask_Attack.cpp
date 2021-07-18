// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "OWAIController.h"
#include "OWCharacter.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
	IsAttacking = false;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AOWCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter)
		return EBTNodeResult::Failed;

	//NPC Attack ����
	//ABCharacter->Attack();
	//IsAttacking = true;
	//ABCharacter->OnAttackEnd.AddLambda([this]()-> void { IsAttacking = false; });

	return EBTNodeResult::InProgress;
}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSecondes)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSecondes);
	//Attack Animation �� Attacking -> false�̸� Task����
	if (!IsAttacking)
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
