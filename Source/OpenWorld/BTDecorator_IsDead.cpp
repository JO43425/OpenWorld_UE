// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_IsDead.h"
#include "OWAIController.h"
#include "OWCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTDecorator_IsDead::UBTDecorator_IsDead()
{
}

bool UBTDecorator_IsDead::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	bool bResult = Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	auto ControllingPawn = Cast<AOWCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ControllingPawn)
		return false;

	return ControllingPawn->IsDead();
}