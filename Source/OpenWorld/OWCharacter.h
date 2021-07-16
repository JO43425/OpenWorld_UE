// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CharacterAnimInterface.h"
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

	const float ToggleRunMinSpeed = 300.0f;
	const float ToggleRunMaxSpeed = 600.0f;
	const float SprintSpeed = 800.0f;
	const float ToggleCrouchSpeed = 200.0f;

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

	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;

public:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void ToggleRun();
	void ResetToggleRunSpeed();
	void Sprint();
	void ReleaseSprint();
	void ToggleCrouch();

public:
	/////////////////////////FOR CAMERA///////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UOWCameraComponent* OWCameraComponent;
	///////////////////////////////////////////////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Animation)
		UAnimMontage* JumpAnimationMontage;

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool EnableToggleRun;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool IsSprint;
};
