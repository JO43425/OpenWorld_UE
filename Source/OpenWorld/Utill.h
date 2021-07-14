// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class OPENWORLD_API Utill
{
public:
	Utill();
	~Utill();

public:
	static float SetParameterByTargetedValue(float& CurrentValue, float TargetedValue, const float ChangeRate, UMaterialParameterCollectionInstance* MaterialParam, FName ParamName = FName(TEXT("")));
};
