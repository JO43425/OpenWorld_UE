// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OWCameraComponent.h"
#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "OWCharacter.generated.h"

UCLASS()
class OPENWORLD_API AOWCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	enum class EControlMode
	{
		THIRD_PERSON,
		END,
	};

public:
	// Sets default values for this character's properties
	AOWCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);

public:
	/////////////////////////FOR CAMERA///////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UOWCameraComponent* OWCameraComponent;
	///////////////////////////////////////////////////////////////////////

};
