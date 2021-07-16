// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OWCharacter.h"
#include "OWPlayer.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLD_API AOWPlayer : public AOWCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AOWPlayer();

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void UpDown(float NewAxisValue) override;
	virtual void LeftRight(float NewAxisValue) override;

public:
	/////////////////////////FOR CAMERA///////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UOWCameraComponent* OWCameraComponent;
};
