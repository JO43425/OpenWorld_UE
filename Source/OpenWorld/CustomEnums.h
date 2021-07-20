// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomEnums.generated.h"
/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponSlot : uint8
{
	FIRST,
	END,
};

UENUM(BlueprintType)
enum class EControlMode : uint8
{
	THIRD_PERSON,
	END,
};

class OPENWORLD_API CustomEnums
{
public:
	CustomEnums();
	~CustomEnums();
};
