// Fill out your copyright notice in the Description page of Project Settings.


#include "RainComponent.h"
#include "Materials/MaterialParameterCollectionInstance.h"

// Sets default values for this component's properties
URainComponent::URainComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	IsUpdate = false;
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
	if (IsUpdate == false)
	{
		return;
	}

	GAME_CHECK(MaterialParam != nullptr);
	RainLevel = RainLevel + ChangeRate;

	if (RainLevel > 1.0f || RainLevel < 0.f)
	{
		IsUpdate = false;
	}

	MaterialParam->SetScalarParameterValue(FName(TEXT("RainLevel")), RainLevel);
}

void URainComponent::SetActiveRain(bool IsEnable)
{
	GAME_CHECK(RainParticle != nullptr);
	GAME_CHECK(RainSound != nullptr);	
	IsUpdate = true;
	if (IsEnable)
	{
		RainParticle->Activate(true);
		RainSound->Play();
		ChangeRate = 0.1f;
	}
	else
	{
		RainParticle->Deactivate();
		RainSound->Stop();
		ChangeRate = -0.1f;
	}
}

