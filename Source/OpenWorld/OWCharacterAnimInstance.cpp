// Fill out your copyright notice in the Description page of Project Settings.


#include "OWCharacterAnimInstance.h"

UOWCharacterAnimInstance::UOWCharacterAnimInstance()
{
	IsCrouch = false;
}

void UOWCharacterAnimInstance::ToggleCrouch(bool Enable)
{
	IsCrouch = Enable;
}

bool UOWCharacterAnimInstance::GetIsCrouch()
{
	return IsCrouch;
}
