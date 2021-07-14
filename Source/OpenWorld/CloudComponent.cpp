// Fill out your copyright notice in the Description page of Project Settings.


#include "CloudComponent.h"
#include "Utill.h"
#include "Materials/MaterialParameterCollectionInstance.h"

// Sets default values for this component's properties
UCloudComponent::UCloudComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	TargetCloudOpacity = 0.f;
	TargetGloomLevel = 0.f;
	// ...
}


// Called when the game starts
void UCloudComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCloudComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UCloudComponent::UpdateCloud(float CurrentCloudOpacity, const float RainChangeRate, UMaterialParameterCollectionInstance* MaterialParam)
{
	if (MaterialParam == nullptr)
	{
		return CurrentCloudOpacity;
	}

	float CurrentGloomLevel;
	if (MaterialParam->GetScalarParameterValue(FName(TEXT("Gloom")), CurrentGloomLevel))
	{
		Utill::SetParameterByTargetedValue(CurrentGloomLevel, TargetGloomLevel, RainChangeRate,  MaterialParam, FName(TEXT("Gloom")));
	}

	CurrentCloudOpacity = Utill::SetParameterByTargetedValue(CurrentCloudOpacity, TargetCloudOpacity, RainChangeRate, MaterialParam);
	return CurrentCloudOpacity;
}

