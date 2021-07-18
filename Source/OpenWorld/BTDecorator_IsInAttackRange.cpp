// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsInAttackRange.h"
#include "OWAIController.h"
#include "OWCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"



UBTDecorator_IsInAttackRange::UBTDecorator_IsInAttackRange()
{
	NodeName = TEXT("CanAttack");
}

bool UBTDecorator_IsInAttackRange::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	auto ControllingPawn = Cast<AOWCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
		return false;


	auto Target = Cast<AOWCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AOWAIController::TargetKey));
	if (nullptr == Target)
	{
		return false;
	}

	if (ControllingPawn->GetFinalAttackRange() == 0.0f)
	{
		return false;
	}
	
	bResult = (Target->GetDistanceTo(ControllingPawn) <= ControllingPawn->GetFinalAttackRange());
	return bResult;
}
