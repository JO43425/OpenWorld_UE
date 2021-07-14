// Fill out your copyright notice in the Description page of Project Settings.


#include "RainComponent.h"
#include "Materials/MaterialParameterCollectionInstance.h"

// Sets default values for this component's properties
URainComponent::URainComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	ChangeRate = 0.1f;
}


// Called when the game starts
void URainComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URainComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void URainComponent::UpdateRain(float DeltaTime, UMaterialParameterCollectionInstance* MaterialParam)
{
	GAME_CHECK(MaterialParam != nullptr);
	float diff = TargetRainLevel - RainLevel;

	if (abs(diff) > 0.1f)
	{
		float changeValue = (diff > 0.f) ? ChangeRate * 1.0f : ChangeRate * -1.0f;
		RainLevel = RainLevel + changeValue;
		MaterialParam->SetScalarParameterValue(FName(TEXT("RainLevel")), RainLevel);
	}
}

void URainComponent::SetActiveRain(bool IsEnable)
{
	GAME_CHECK(RainParticle != nullptr);
	GAME_CHECK(RainSound != nullptr);	

	if (IsEnable)
	{
		RainParticle->Activate(true);
		RainSound->Play();
		TargetRainLevel = 0.9f;
	}
	else
	{
		RainParticle->Deactivate();
		RainSound->Stop();
		TargetRainLevel = 0.0f;
	}
}

