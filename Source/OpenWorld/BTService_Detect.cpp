// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_Detect.h"
#include "OWAIController.h"
#include "OWCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"


UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{

	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn) return;

	UWorld* World = ControllingPawn->GetWorld();
	FVector Center = ControllingPawn->GetActorLocation();
	float DetectRadius = 600.0f;

	if (nullptr == World) return;
	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParm(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel3,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParm);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			AOWCharacter* OWCharacter = Cast<AOWCharacter>(OverlapResult.GetActor());
			if (OWCharacter && OWCharacter->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(AOWAIController::TargetKey, OWCharacter);
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
				DrawDebugPoint(World, OWCharacter->GetActorLocation(), 10.0f, FColor::Blue, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), OWCharacter->GetActorLocation(), FColor::Blue, false, 0.2f);
				return;
			}
		}
	}
}