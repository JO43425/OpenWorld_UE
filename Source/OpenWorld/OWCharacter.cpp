// Fill out your copyright notice in the Description page of Project Settings.

#include "OWCharacter.h"

// Sets default values
AOWCharacter::AOWCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OWCameraComponent = CreateDefaultSubobject<UOWCameraComponent>(TEXT("OWCamera"));
	this->AddOwnedComponent(OWCameraComponent);
	OWCameraComponent->Init(this, CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")), CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")));
	OWCameraComponent->SetControlMode(UOWCameraComponent::EControlMode::THIRD_PERSON);
}

// Called when the game starts or when spawned
void AOWCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void AOWCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOWCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AOWCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AOWCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), OWCameraComponent, &UOWCameraComponent::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), OWCameraComponent, &UOWCameraComponent::LookUp);
}

void AOWCharacter::UpDown(float NewAxisValue)
{
	GAME_CHECK(nullptr != OWCameraComponent);
	UOWCameraComponent::EControlMode CurrentControlMode = OWCameraComponent->GetCurrentControlMode();

	switch (CurrentControlMode)
	{
	case UOWCameraComponent::EControlMode::THIRD_PERSON:
	{
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
	}
	break;
	default:
		break;
	}
}

void AOWCharacter::LeftRight(float NewAxisValue)
{
	GAME_CHECK(nullptr != OWCameraComponent);
	UOWCameraComponent::EControlMode CurrentControlMode = OWCameraComponent->GetCurrentControlMode();

	switch (CurrentControlMode)
	{
	case UOWCameraComponent::EControlMode::THIRD_PERSON:
	{
		AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
	}
	break;
	default:
		break;
	}
}

