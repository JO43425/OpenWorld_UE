// Fill out your copyright notice in the Description page of Project Settings.

#include "OWCharacterAnimInstance.h"
#include "OWCharacter.h"

// Sets default values
AOWCharacter::AOWCharacter()
	:EnableToggleRun(true)
	,IsSprint(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> JUMP_MONTAGE(TEXT("/Game/Character/Knight/Animations/Jump_Montage"));
	if (JUMP_MONTAGE.Succeeded())
	{
		JumpAnimationMontage = JUMP_MONTAGE.Object;
	}
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

void AOWCharacter::Jump()
{
	if (GetCharacterMovement()->IsFalling())
	{
		return;
	}

	Super::Jump();
	GAME_CHECK(JumpAnimationMontage != nullptr);
	PlayAnimMontage(JumpAnimationMontage);
}

void AOWCharacter::Landed(const FHitResult& Hit)
{
	Super::Jump();

	GAME_CHECK(JumpAnimationMontage != nullptr);
	PlayAnimMontage(JumpAnimationMontage, 1.0f, FName(TEXT("Land")));
}

void AOWCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AOWCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(FRotator(0.0f, GetControlRotation().Yaw, 0.0f)).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AOWCharacter::ToggleRun()
{
	EnableToggleRun = !EnableToggleRun;

	ResetToggleRunSpeed();
}

void AOWCharacter::ResetToggleRunSpeed()
{
	if (EnableToggleRun)
	{
		GetCharacterMovement()->MaxWalkSpeed = ToggleRunMaxSpeed;
	}
	else
	{
		GetCharacterMovement()->MaxWalkSpeed = ToggleRunMinSpeed;
	}
}

void AOWCharacter::Sprint()
{
	IsSprint = true;
	auto AnimInstance = Cast< UOWCharacterAnimInstance>(GetMesh()->GetAnimInstance());
	GAME_CHECK(AnimInstance);
	AnimInstance->ToggleCrouch(false);
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AOWCharacter::ReleaseSprint()
{
	IsSprint = false;
	ResetToggleRunSpeed();
}

void AOWCharacter::ToggleCrouch()
{
	auto AnimInstance = Cast< UOWCharacterAnimInstance>( GetMesh()->GetAnimInstance());
	GAME_CHECK(AnimInstance);

	bool Enable = !AnimInstance->GetIsCrouch();	
	if (Enable)
	{
		GetCharacterMovement()->MaxWalkSpeed = ToggleCrouchSpeed;
	}
	else
	{
		ResetToggleRunSpeed();
	}
	
	AnimInstance->ToggleCrouch(Enable);
}

