// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SeasonComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPENWORLD_API USeasonComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	enum E_SEASON
	{
		SPRING,
		SUMMER,
		AUTUMN,
		WINTER,
		END,
	};
public:	
	// Sets default values for this component's properties
	USeasonComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetSeason(FName SeasonName, float TargetValue = 1.0);

	UFUNCTION(BlueprintCallable)
	void UpdateSeason(UMaterialParameterCollectionInstance* MaterialParam);
		
public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Season, Meta = (AllowPrivateAcess = true))
		float CurrentSeasonValue;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Season, Meta = (AllowPrivateAcess = true))
		float ChangeRate;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Season, Meta = (AllowPrivateAcess = true))
		float TargetSeasonValue;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Season, Meta = (AllowPrivateAcess = true))
		FName TargetSeasonName;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Season, Meta = (AllowPrivateAcess = true))
		FName CurrentSeasonName;
};
