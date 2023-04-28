// Fill out your copyright notice in the Description page of Project Settings.

#include "TailElement.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakePawn.h"



// Sets default values
ATailElement::ATailElement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TailStaticMeshComponent = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SetRootComponent(TailStaticMeshComponent);
	TailStaticMeshComponent->SetGenerateOverlapEvents(true);

	Tags.Add(FName("TailElement"));
}

// Called when the game starts or when spawned
void ATailElement::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATailElement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

