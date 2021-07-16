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

	OWCameraComponent = CreateDefaultSubobject<UOWCameraComponent>(TEXT("OWCamera"));
	this->AddOwnedComponent(OWCameraComponent);
	OWCameraComponent->Init(this, CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")), CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")));
	OWCameraComponent->SetControlMode(UOWCameraComponent::EControlMode::THIRD_PERSON);

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

// Called to bind functionality to input
void AOWCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AOWCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AOWCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), OWCameraComponent, &UOWCameraComponent::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), OWCameraComponent, &UOWCameraComponent::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AOWCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("ToggleRun"), EInputEvent::IE_Pressed, this, &AOWCharacter::ToggleRun);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &AOWCharacter::Sprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &AOWCharacter::ReleaseSprint);
	PlayerInputComponent->BindAction(TEXT("ToggleCrouch"), EInputEvent::IE_Pressed, this, &AOWCharacter::ToggleCrouch);
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

