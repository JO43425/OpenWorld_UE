// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponEquipComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPENWORLD_API UWeaponEquipComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponEquipComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void UseWeapon(bool IsUse, class UOWCharacterAnimInstance* Anim);
	void HandSocketChange(AActor* Owner, class USceneComponent* Parent);
	void Initialize(const FName& UseName, const FName& UnUseName);
	void SetWeapon(class AWeapon* Weapon, USceneComponent* Target, AActor* Owner );
	const FWeaponEquipInfo& GetEquipInfo() const;

public:
	FWeaponEquipInfo EquipInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName UseSocketName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName UnUseSocketName;
};
