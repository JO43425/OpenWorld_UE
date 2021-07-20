// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "WeaponEquipComponent.h"
#include "CoreMinimal.h"
#include "OWCharacter.h"
#include "OWPlayer.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLD_API AOWPlayer : public AOWCharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AOWPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	virtual void PostInitializeComponents() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void UpDown(float NewAxisValue) override;
	virtual void LeftRight(float NewAxisValue) override;
	virtual void ToggleFirstWeapon() override;

	void OnEquipSocketChange();

public:
	/////////////////////////FOR CAMERA///////////////////////////////
	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UOWCameraComponent* OWCameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, Meta = (AllowPrivateAcess = true))
		TArray<UWeaponEquipComponent*> WeaponEquips;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, Meta = (AllowPrivateAcess = true))
		USceneComponent* HandSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon, Meta = (AllowPrivateAcess = true))
		USceneComponent* SwordStrap;

	//Test
	UPROPERTY(EditInstanceOnly, Category = Test)
		TSubclassOf<class AWeapon> WeaponItemClass;
protected:
	EWeaponSlot CurrentWeaponSlot;
};
