// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OWCharacter.h"
#include "OWHuman.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLD_API AOWHuman : public AOWCharacter
{
	GENERATED_BODY()

public:
	AOWHuman();

protected:
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
public:
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY()
		class AOWAIController* AIController;
};
