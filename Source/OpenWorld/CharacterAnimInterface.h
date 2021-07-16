// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CharacterAnimInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterAnimInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OPENWORLD_API ICharacterAnimInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ToggleCrouch(bool Enable) = 0;
};
