// Fill out your copyright notice in the Description page of Project Settings.


#include "SeasonComponent.h"

// Sets default values for this component's properties
USeasonComponent::USeasonComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	ChangeRate = 0.1f;
	// ...
}


// Called when the game starts
void USeasonComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USeasonComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USeasonComponent::SetSeason(FName SeasonName,float TargetValue)
{
	CurrentSeasonName = TargetSeasonName;
	TargetSeasonName = SeasonName;
}

void USeasonComponent::UpdateSeason(UMaterialParameterCollectionInstance* MaterialParam)
{
}

