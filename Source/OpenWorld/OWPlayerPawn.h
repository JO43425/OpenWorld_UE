// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "OpenWorld.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "OWPlayerPawn.generated.h"

UCLASS()
class OPENWORLD_API AOWPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AOWPlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

	UPROPERTY(VisibleAnyWhere, Category = Collision)
		UCapsuleComponent* Capsule;
	UPROPERTY(VisibleAnyWhere, Category = Visual)
		USkeletalMeshComponent* Mesh;
	UPROPERTY(VisibleAnyWhere, Category = Movement)
		UFloatingPawnMovement* Movement;

	UPROPERTY(VisibleAnyWhere, Category = Camera)
		USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnyWhere, Category = Camera)
		UCameraComponent* Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);

};
