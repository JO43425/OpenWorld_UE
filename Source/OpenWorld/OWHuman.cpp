// Fill out your copyright notice in the Description page of Project Settings.


#include "OWAIController.h"
#include "OWHuman.h"

AOWHuman::AOWHuman()
{
}

void AOWHuman::BeginPlay()
{
	Super::BeginPlay();
	AIController = Cast<AOWAIController>(GetController());
	GAME_CHECK(nullptr != AIController);
	AIController->RunAI();
}

void AOWHuman::BeginDestroy()
{
	Super::BeginDestroy();
	GAME_CHECK(nullptr != AIController);
	AIController->StopAI();
}

void AOWHuman::Tick(float DeltaTime)
{
}
