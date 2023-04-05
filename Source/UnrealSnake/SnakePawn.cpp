// Fill out your copyright notice in the Description page of Project Settings.

#include "SnakePawn.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "TailElement.h"
#include "Algo/Reverse.h"



// Sets default values
ASnakePawn::ASnakePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create our components
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(CapsuleComponent);
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
	//GetWorldTimerManager().SetTimer(TimerHandle, this, &ASnakePawn::MoveTail, 1.0f, true, 2.0f);
}

// Called every frame
void ASnakePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	 
	SnakePrevLocation = GetActorLocation();

	if (!TailElements.IsEmpty())
	{
		MoveTail();
	}
}

// Called to bind functionality to input
void ASnakePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

int32 ASnakePawn::GetScores()
{
	return Scores;
}


//Precess of eating food and adding scores
void ASnakePawn::EatFood()
{
	AddTailElement();
	UpdateScores();
}
 
//After "eating" food element we should add a new tailElement to out snake's tail
//So, we spawn it
void ASnakePawn::AddTailElement()
{
	if (IsValid(TailElementToSpawn) && GetWorld())
	{
		FVector NewLocation;

		if (LastAddedElement)
		{
			NewLocation = LastAddedElement->GetActorLocation() - LastAddedElement->GetActorForwardVector() * StepSize;
		}
		else
		{
			NewLocation = GetActorLocation() - GetActorForwardVector() * StepSize;
		}
		NewLocation.Z = 0;

		LastAddedElement = GetWorld()->SpawnActor<ATailElement>(TailElementToSpawn, NewLocation, FRotator(0,0,0));
		TailElements.Add(LastAddedElement);
	}
}

//Moves tail elements one by one during Snake head movement
void ASnakePawn::MoveTail()
{
	for (auto element: TailElements)
	{
		auto delta = SnakePrevLocation - element->GetActorLocation();
		delta.Normalize();

		FVector NewLocation = SnakePrevLocation - delta * StepSize;
		NewLocation.Z = 0;
		
		FRotator NewRotation = element->GetActorRotation();
		NewRotation.Yaw = UKismetMathLibrary::RadiansToDegrees(-atan2f(delta.X, delta.Y));

		element->SetActorRotation(NewRotation);
		element->SetActorLocation(NewLocation);

		SnakePrevLocation = NewLocation;
	}
}

void ASnakePawn::UpdateScores()
{
	Scores++;
}

