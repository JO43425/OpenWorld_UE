// Fill out your copyright notice in the Description page of Project Settings.


#include "OWPlayerPawn.h"

// Sets default values
AOWPlayerPawn::AOWPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	/*
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_CARDBOARD(TEXT("SkeletalMesh'/Game/Character/Knight/Knight_RM"));
	if (SK_CARDBOARD.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_CARDBOARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	FString path = L"AnimBlueprint'/Game/InfinityBladeWarriors/Animation/WarriorAnimBlueprint'";
	static ConstructorHelpers::FClassFinder<UAnimInstance> WARRIOR_ANIM(*path);
	if (WARRIOR_ANIM.Succeeded())
	{
		Mesh->SetAnimInstanceClass(WARRIOR_ANIM.Class);
	}
	*/

}

// Called when the game starts or when spawned
void AOWPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOWPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOWPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AOWPlayerPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AOWPlayerPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void AOWPlayerPawn::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AOWPlayerPawn::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

