// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponEquipComponent.h"
#include "OWCharacterAnimInstance.h"
#include "Weapon.h"

// Sets default values for this component's properties
UWeaponEquipComponent::UWeaponEquipComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	EquipInfo.Weapon = nullptr;
	EquipInfo.IsUsing = false;
	// ...
}


// Called when the game starts
void UWeaponEquipComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UWeaponEquipComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponEquipComponent::UseWeapon(bool IsUse, class UOWCharacterAnimInstance* Anim)
{
	GAME_CHECK(EquipInfo.Weapon != nullptr);
	EquipInfo.IsUsing = IsUse;
	Anim->PlayEquipMontage();
}

void UWeaponEquipComponent::HandSocketChange(AActor* Owner, USceneComponent* Parent)
{
	GAME_CHECK(EquipInfo.Weapon != nullptr);
	EquipInfo.Weapon->AttachToComponent(Parent, FAttachmentTransformRules::KeepRelativeTransform);
}

void UWeaponEquipComponent::Initialize(const FName& UseName, const FName& UnUseName)
{
	UseSocketName = UseName;
	UnUseSocketName = UnUseName;
}

void UWeaponEquipComponent::SetWeapon(AWeapon* Weapon, USceneComponent* Target, AActor* Owner)
{
	if (EquipInfo.Weapon != nullptr)
	{
		EquipInfo.Weapon->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		EquipInfo.Weapon->Destroy();
		EquipInfo.Weapon = nullptr;
	}
	
	if(Weapon != nullptr)
	{
		Weapon->AttachToComponent(Target, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		Weapon->SetOwner(Owner);
		EquipInfo.Weapon = Weapon;
	}
}

const FWeaponEquipInfo& UWeaponEquipComponent::GetEquipInfo() const
{
	return EquipInfo;
}

