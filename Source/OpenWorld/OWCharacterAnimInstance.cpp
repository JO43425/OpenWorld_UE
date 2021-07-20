// Fill out your copyright notice in the Description page of Project Settings.


#include "OWCharacterAnimInstance.h"

UOWCharacterAnimInstance::UOWCharacterAnimInstance()
{
	IsCrouch = false;
	
	static ConstructorHelpers::FObjectFinder<UAnimMontage> EQUIP_S_MONTAGE(TEXT("/Game/Character/Knight/Sword/Unarmed_Equip_Over_Shoulder_Montage"));
	if (EQUIP_S_MONTAGE.Succeeded())
	{
		EquipMontage = EQUIP_S_MONTAGE.Object;
	}	
}

void UOWCharacterAnimInstance::PlayEquipMontage()
{
	GAME_CHECK(EquipMontage != nullptr);
	Montage_Play(EquipMontage, 1.0f);
}

void UOWCharacterAnimInstance::ToggleCrouch(bool Enable)
{
	IsCrouch = Enable;
}

bool UOWCharacterAnimInstance::GetIsCrouch()
{
	return IsCrouch;
}

void UOWCharacterAnimInstance::AnimNotify_EquipSocketChange()
{
	OnEquipSocketChange.Broadcast();
}
