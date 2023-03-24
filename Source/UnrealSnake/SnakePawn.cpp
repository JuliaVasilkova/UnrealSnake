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

	//Last added tail element location by default is head location
	LastAddedTransform = GetActorTransform();
}

// Called when the game starts or when spawned
void ASnakePawn::BeginPlay()
{
	Super::BeginPlay();
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

void ASnakePawn::AddTailElement()
{
	if (IsValid(TailElementToSpawn) && GetWorld())
	{
		LastAddedElement = GetWorld()->SpawnActor<ATailElement>(TailElementToSpawn, GetElementTransform());
		TailElements.Add(LastAddedElement);
	}
}

FTransform ASnakePawn::GetElementTransform()
{
	int32 StepSize = 60;

	if (isFirst)
	{
		isFirst = false;
	}
	else
	{
		if (LastAddedElement)
		{
			LastAddedTransform = LastAddedElement->GetActorTransform();
			
			FVector NewLocation = LastAddedTransform.GetLocation() - GetActorForwardVector() * StepSize;
			LastAddedTransform.SetLocation(FVector(NewLocation.X, NewLocation.Y, 30));
		}

	}
	return LastAddedTransform;
}

void ASnakePawn::UpdateScores()
{
	Scores++;
}

