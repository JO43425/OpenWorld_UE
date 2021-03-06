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
	virtual void PostInitializeComponents() override;
	virtual void Jump() override;
	virtual void Landed(const FHitResult& Hit) override;

public:
	virtual void UpDown(float NewAxisValue);
	virtual void LeftRight(float NewAxisValue);
	virtual bool IsDead();
	virtual float GetFinalAttackRange();

	//Toggle Actions
	void ToggleRun();
	void ResetToggleRunSpeed();
	void Sprint();
	void ReleaseSprint();
	void ToggleCrouch();
	void SetRun();
	void ReleaseCrouch();
	void ResetIdle();
	UFUNCTION(BlueprintCallable)
	virtual void ToggleFirstWeapon();
	///////////////////////////////////////////////////////////////////////

public:
	///////////////////////////////////////////////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Animation)
		UAnimMontage* JumpAnimationMontage;

protected:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool EnableToggleRun;
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool IsSprint;
	UPROPERTY(VisibleAnyWhere, Category = Weapon)
		class AWeapon* CurrentWeapon;
	UPROPERTY()
		class UOWCharacterAnimInstance* OWAnim;
};
