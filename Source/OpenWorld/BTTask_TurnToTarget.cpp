// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_TurnToTarget.h"
#include "OWAIController.h"
#include "OWCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_TurnToTarget::UBTTask_TurnToTarget()
{
	NodeName = TEXT("Turn");
}

EBTNodeResult::Type UBTTask_TurnToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto ABCharacter = Cast<AOWCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (nullptr == ABCharacter)
		return EBTNodeResult::Failed;

	auto Target = Cast<AOWCharacter>(OwnerComp.GetBlackboardComponent()->GetValueAsObject(AOWAIController::TargetKey));
	if (nullptr == Target)
	{
		return EBTNodeResult::Failed;
	}

	FVector LookVector = Target->GetActorLocation() - ABCharacter->GetActorLocation();
	LookVector.Z = 0.0f;
	FRotator TargetRot = FRotationMatrix::MakeFromX(LookVector).Rotator();
	ABCharacter->SetActorRotation(FMath::RInterpTo(ABCharacter->GetActorRotation(), TargetRot, GetWorld()->GetDeltaSeconds(), 2.0f));

	return EBTNodeResult::Succeeded;
}
