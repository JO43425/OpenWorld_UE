// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CloudComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPENWORLD_API UCloudComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCloudComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	float UpdateCloud(float CurrentCloudOpacity, const float RainChangeRate, UMaterialParameterCollectionInstance* MaterialParam);

public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Cloud, Meta = (AllowPrivateAcess = true))
	float TargetCloudOpacity;
};
