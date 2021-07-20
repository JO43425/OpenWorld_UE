// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CharacterAnimInterface.h"
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "OWCharacterAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEquipSocketChange);
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
	void PlayEquipMontage();
	FOnEquipSocketChange OnEquipSocketChange;
private:
	UFUNCTION()
		void AnimNotify_EquipSocketChange();
protected:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Movement, Meta = (AllowPrivateAcess = true))
		bool IsCrouch;
	UPROPERTY(EditAnywhere, Category = Animation)
		UAnimMontage* EquipMontage;
};
