// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "RainComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeatherController.generated.h"

UCLASS()
class OPENWORLD_API AWeatherController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeatherController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnToggleRain(bool IsEnable);
	virtual void OnToggleRain_Implementation(bool IsEnable);

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Component)
		URainComponent* RainComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = MaterialParameter)
		UMaterialParameterCollection* Global_MP;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = MaterialParameter)
		UMaterialParameterCollectionInstance* Global_MPI;
};
