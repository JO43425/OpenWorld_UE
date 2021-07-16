// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CharacterAnimInterface.h"
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "OWCharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLD_API UOWCharacterAnimInstance : public UAnimInstance, public ICharacterAnimInterface
{
	GENERATED_BODY()
	
public:
	UOWCharacterAnimInstance();

public:
	virtual void ToggleCrouch(bool Enable) override;

public:
	bool GetIsCrouch();

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool IsCrouch;
};
