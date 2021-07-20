// Fill out your copyright notice in the Description page of Project Settings.


#include "OWPlayer.h"
#include "OWCharacterAnimInstance.h"

AOWPlayer::AOWPlayer()
{
	OWCameraComponent = CreateDefaultSubobject<UOWCameraComponent>(TEXT("OWCamera"));
	this->AddOwnedComponent(OWCameraComponent);
	OWCameraComponent->Init(this, CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")), CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")));
	OWCameraComponent->SetControlMode(UOWCameraComponent::EControlMode::THIRD_PERSON);
	CurrentWeaponSlot = EWeaponSlot::END;

	HandSocket = CreateDefaultSubobject<USceneComponent>(TEXT("HAND_SOCKET"));
	SwordStrap = CreateDefaultSubobject<USceneComponent>(TEXT("SWORD_STRAP"));
	HandSocket->SetupAttachment(GetMesh(), FName(TEXT("SwordInHandSocket")));
	SwordStrap->SetupAttachment(GetMesh(), FName(TEXT("Sword1Socket")));
	//HandSocket->AttachTo(GetMesh(), FName("SwordInHandSocket"));
	//SwordStrap->AttachTo(GetMesh(), FName("SwordStrap"));
	UWeaponEquipComponent* WeaponComponent = CreateDefaultSubobject<UWeaponEquipComponent>(TEXT("Weapon1"));
	WeaponComponent->Initialize(FName(TEXT("SwordInHandSocket")), FName(TEXT("Sword1Socket")));
	WeaponEquips.Add(WeaponComponent);
	WeaponItemClass = AWeapon::StaticClass();
}

void AOWPlayer::BeginPlay()
{
	Super::BeginPlay();

	//Test
	UWeaponEquipComponent* WeaponComponent = WeaponEquips[(uint8)EWeaponSlot::FIRST];
	auto NewWeapon = GetWorld()->SpawnActor<AWeapon>(WeaponItemClass, FVector::ZeroVector, FRotator::ZeroRotator);
	WeaponComponent->SetWeapon(NewWeapon, SwordStrap, this);
}

void AOWPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	GAME_CHECK(OWAnim != nullptr);
	OWAnim->OnEquipSocketChange.AddUObject(this, &AOWPlayer::OnEquipSocketChange);
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
	PlayerInputComponent->BindAction(TEXT("ToggleFirstWeapon"), EInputEvent::IE_Pressed, this, &AOWPlayer::ToggleFirstWeapon);
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

void AOWPlayer::ToggleFirstWeapon()
{
	GAME_CHECK(WeaponEquips.Num() >= (uint8)EWeaponSlot::FIRST);
	UWeaponEquipComponent* EquipComponent = WeaponEquips[(uint8)EWeaponSlot::FIRST];
	GAME_CHECK(EquipComponent != nullptr);
	auto info = EquipComponent->GetEquipInfo();
	CurrentWeaponSlot = EWeaponSlot::FIRST;
	EquipComponent->UseWeapon(!info.IsUsing, OWAnim);
}
void AOWPlayer::OnEquipSocketChange()
{
	uint8 slot = (uint8)CurrentWeaponSlot;
	GAME_CHECK(WeaponEquips.Num() >= slot);
	UWeaponEquipComponent* EquipComponent = WeaponEquips[slot];
	GAME_CHECK(EquipComponent != nullptr);

	if (EquipComponent->GetEquipInfo().IsUsing)
	{
		EquipComponent->HandSocketChange(this, HandSocket);
	}
	else
	{
		EquipComponent->HandSocketChange(this, SwordStrap);
	}	
}
//ABAnim->OnMontageEnded.AddDynamic(this, &AABCharacter::OnAttackMontageEnded);