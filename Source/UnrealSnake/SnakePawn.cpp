// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakePawn.h"

// Sets default values
ASnakePawn::ASnakePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SphereStaticMeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("SphereStaticMeshComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	MoveComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MoveComponent"));


	//Attach our components
	SphereStaticMeshComponent->SetupAttachment(CapsuleComponent);
	SpringArmComp->SetupAttachment(SphereStaticMeshComponent);
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

	//Setup SphereStaticMeshComponent
	SphereStaticMeshComponent->bUseDefaultCollision = true;
	SphereStaticMeshComponent->SetEnableGravity(true);
	

	//Assign SpringArm class variables.
	SpringArmComp->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(0.0f, -30.0f, 0.0f));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->TargetArmLength = 500.f;

}

// Called when the game starts or when spawned
void ASnakePawn::BeginPlay()
{
	Super::BeginPlay();

//	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
//	{
//		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
//		{
//			Subsystem->ClearAllMappings();
//			Subsystem->AddMappingContext(PawnInputMappingContext, 0);
//		}
//	}
//	
}

// Called every frame
void ASnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}

// Called to bind functionality to input
void ASnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

