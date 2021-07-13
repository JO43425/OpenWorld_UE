// Fill out your copyright notice in the Description page of Project Settings.


#include "WeatherController.h"

// Sets default values
AWeatherController::AWeatherController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 1.0f;

	RainComponent = CreateDefaultSubobject<URainComponent>(TEXT("RainComponent"));
}

// Called when the game starts or when spawned
void AWeatherController::BeginPlay()
{
	Super::BeginPlay();
	Global_MPI = GetWorld()->GetParameterCollectionInstance(Global_MP);
	/*
	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
	{
	}), 5.0f, false); 
	*/		
}

// Called every frame
void AWeatherController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RainComponent)
	{
		RainComponent->UpdateRain(DeltaTime, Global_MPI);
	}
}

void AWeatherController::OnToggleRain_Implementation(bool IsEnable)
{
	if (RainComponent)
	{
		RainComponent->SetActiveRain(IsEnable);
	}
}

