// Fill out your copyright notice in the Description page of Project Settings.


#include "OWAIController.h"
#include "Navigation/CrowdFollowingComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

const FName AOWAIController::HomePosKey(TEXT("HomePos"));
const FName AOWAIController::PatrolPosKey(TEXT("PatrolPos"));
const FName AOWAIController::TargetKey(TEXT("Target"));

AOWAIController::AOWAIController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/AI/BB_Enemy.BB_Enemy"));
	if (BBObject.Succeeded())
	{
		BBAsset = BBObject.Object;
	}

	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/AI/BT_Enemy.BT_Enemy"));
	if (BTObject.Succeeded())
	{
		BTAsset = BTObject.Object;
	}
}

void AOWAIController::RunAI()
{
	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsVector(HomePosKey, GetPawn()->GetActorLocation());
		if (!RunBehaviorTree(BTAsset))
		{
			GAME_LOG(Error, TEXT("AIController couldn't run behavior tree!"));
		}
	}
}

void AOWAIController::StopAI()
{
	auto BehaviorTreeComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (nullptr != BehaviorTreeComponent)
	{
		BehaviorTreeComponent->StopTree(EBTStopMode::Safe);
	}
}
