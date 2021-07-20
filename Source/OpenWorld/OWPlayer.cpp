// Fill out your copyright notice in the Description page of Project Settings.


#include "OWPlayer.h"

AOWPlayer::AOWPlayer()
{
	OWCameraComponent = CreateDefaultSubobject<UOWCameraComponent>(TEXT("OWCamera"));
	this->AddOwnedComponent(OWCameraComponent);
	OWCameraComponent->Init(this, CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")), CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")));
	OWCameraComponent->SetControlMode(UOWCameraComponent::EControlMode::THIRD_PERSON);
}

void AOWPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AOWPlayer::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AOWPlayer::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), OWCameraComponent, &UOWCameraComponent::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), OWCameraComponent, &UOWCameraComponent::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AOWCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("ToggleRun"), EInputEvent::IE_Pressed, this, &AOWCharacter::ToggleRun);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &AOWCharacter::Sprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &AOWCharacter::ReleaseSprint);
	PlayerInputComponent->BindAction(TEXT("ToggleCrouch"), EInputEvent::IE_Pressed, this, &AOWCharacter::ToggleCrouch);
	PlayerInputComponent->BindAction(TEXT("ToggleFirstWeapon"), EInputEvent::IE_Pressed, this, &AOWCharacter::ToggleFirstWeapon);
}

void AOWPlayer::UpDown(float NewAxisValue)
{
	GAME_CHECK(nullptr != OWCameraComponent);
	UOWCameraComponent::EControlMode CurrentControlMode = OWCameraComponent->GetCurrentControlMode();

	switch (CurrentControlMode)
	{
	case UOWCameraComponent::EControlMode::THIRD_PERSON:
	{
		Super::UpDown(NewAxisValue);
	}
	break;
	default:
		break;
	}
}

void AOWPlayer::LeftRight(float NewAxisValue)
{
	GAME_CHECK(nullptr != OWCameraComponent);
	UOWCameraComponent::EControlMode CurrentControlMode = OWCameraComponent->GetCurrentControlMode();

	switch (CurrentControlMode)
	{
	case UOWCameraComponent::EControlMode::THIRD_PERSON:
	{
		Super::LeftRight(NewAxisValue);
	}
	break;
	default:
		break;
	}
}
