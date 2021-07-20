// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
/*
* Struct Base Code
USTRUCT(Atomic, BlueprintType)
struct FName
{
	GENERATED_USTRUCT_BODY()
public:
	FName();
	~FName();
};

//Variable
UPROPERTY(EditAnywhere, BlueprintReadWrite)
int32 name;
*/

#include "CoreMinimal.h"
#include "CustomStructs.generated.h"

class AWeapon;
/**
 * 
 */
class OPENWORLD_API CustomStructs
{
public:
	CustomStructs();
	~CustomStructs();
};

USTRUCT(Atomic, BlueprintType)
struct FItemInfo
{
	GENERATED_USTRUCT_BODY()
public:
	FItemInfo();
	~FItemInfo();
};

USTRUCT(Atomic, BlueprintType)
struct FWeaponEquipInfo
{
	GENERATED_USTRUCT_BODY()
public:
	FWeaponEquipInfo();
	virtual ~FWeaponEquipInfo();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class AWeapon* Weapon;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsUsing;
};