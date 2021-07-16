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

public:
	virtual void Tick(float DeltaTime) override;
	
};
