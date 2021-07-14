// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class OPENWORLD_API SeasonInfo
{
public:
	SeasonInfo();
	~SeasonInfo();

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Season, Meta = (AllowPrivateAcess = true))
		float TargetSeasonValue;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Season, Meta = (AllowPrivateAcess = true))
		FName TargetSeasonName;
};
