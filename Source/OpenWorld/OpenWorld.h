// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CustomEnums.h"
#include "CustomStructs.h"
#include "CoreMinimal.h"
#include "EngineMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(OpenWorld, Log, All);
#define GAME_LOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define GAME_LOG_S(Verbosity) UE_LOG(OpenWorld, Verbosity, TEXT("%s"), *GAME_LOG_CALLINFO)
#define GAME_LOG(Verbosity, Format, ...) UE_LOG(OpenWorld, Verbosity, TEXT("%s%s"), *GAME_LOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
#define GAME_CHECK(Expr, ...) { if(!(Expr)) { GAME_LOG(Error, TEXT("ASSERTION : %s"), TEXT("'"#Expr"'")); return __VA_ARGS__; }}