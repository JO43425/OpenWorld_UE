// Fill out your copyright notice in the Description page of Project Settings.


#include "OWCameraComponent.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UOWCameraComponent::UOWCameraComponent()
	:ArmLengthSpeed(3.0f)
	,ArmLengthTo(450.0f)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOWCameraComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOWCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SpringArm)
	{
		SpringArm->TargetArmLength = FMath::FInterpTo(SpringArm->TargetArmLength, ArmLengthTo, DeltaTime, ArmLengthSpeed);
	}
}

void UOWCameraComponent::SetControlMode(EControlMode eControlMode)
{
	CurrentControlMode = eControlMode;
	if (eControlMode == EControlMode::THIRD_PERSON)
	{
		ArmLengthTo = 450.0f;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;
		Character->bUseControllerRotationYaw = false;
		Character->GetCharacterMovement()->bOrientRotationToMovement = true;
		Character->GetCharacterMovement()->bUseControllerDesiredRotation = false;
		Character->GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);
	}
}

void UOWCameraComponent::Init(ACharacter* pCharacter, USpringArmComponent* pSpringArm, UCameraComponent* pCamera)
{
	if (pCharacter == nullptr || pSpringArm == nullptr || pCamera == nullptr)
	{
		return;
	}

	Character = pCharacter;
	SpringArm = pSpringArm;
	Camera = pCamera;
	SpringArm->SetupAttachment(Character->GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));	
}

void UOWCameraComponent::Turn(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::THIRD_PERSON:
	{
		Character->AddControllerYawInput(NewAxisValue);
	}
		break;
	default:
		break;
	}
}

void UOWCameraComponent::LookUp(float NewAxisValue)
{
	switch (CurrentControlMode)
	{
	case EControlMode::THIRD_PERSON:
	{
		Character->AddControllerPitchInput(NewAxisValue);
	}
	break;
	default:
		break;
	}
}

UOWCameraComponent::EControlMode UOWCameraComponent::GetCurrentControlMode()
{
	return CurrentControlMode;
}

