// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UObjectGlobals.h"
#include "AIController.h"
#include "OWAIController.generated.h"

/**
 * 
 */
UCLASS()
class AOWAIController : public AAIController
{
	GENERATED_BODY()
public:
	AOWAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;

	void RunAI();
	void StopAI();

protected:

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = BehaviorTree, Meta = (AllowPrivateAcess = true))
		class UBehaviorTree* BTAsset;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = BlackBoard, Meta = (AllowPrivateAcess = true))
		class UBlackboardData* BBAsset;
};
