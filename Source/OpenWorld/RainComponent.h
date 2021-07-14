// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RainComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPENWORLD_API URainComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URainComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void UpdateRain(float DeltaTime, UMaterialParameterCollectionInstance* MaterialParam);
	void SetActiveRain(bool IsEnable);

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Rain, Meta = (AllowPrivateAcess = true))
		float RainLevel;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Rain, Meta = (AllowPrivateAcess = true))
		float ChangeRate;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Rain, Meta = (AllowPrivateAcess = true))
		float TargetRainLevel;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Rain)
		UParticleSystemComponent* RainParticle;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = Rain)
		UAudioComponent* RainSound;
};
