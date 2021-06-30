// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OWCameraComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OPENWORLD_API UOWCameraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	enum class EControlMode
	{
		THIRD_PERSON,
		END,
	};

public:	
	// Sets default values for this component's properties
	UOWCameraComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void SetControlMode(EControlMode eControlMode);
	void Init(ACharacter* pCharacter, USpringArmComponent* pSpringArm, UCameraComponent* pCamera);

public:
	/////////////////////////FOR CAMERA///////////////////////////////
	EControlMode CurrentControlMode = EControlMode::THIRD_PERSON;
	float ArmLengthTo = 0.0f;
	float ArmLengthSpeed = 0.0f;

	UPROPERTY(VisibleAnyWhere, Category = Camera)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UCameraComponent* Camera;

	class ACharacter* Character;
	///////////////////////////////////////////////////////////////////////
};
