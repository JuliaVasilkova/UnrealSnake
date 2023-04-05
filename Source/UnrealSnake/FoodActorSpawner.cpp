// Fill out your copyright notice in the Description page of Project Settings.

#include "FoodActorSpawner.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "FoodActor.h"


// Sets default values
AFoodActorSpawner::AFoodActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.TickInterval = 3;

}

// Called when the game starts or when spawned
void AFoodActorSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFoodActorSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// floor size is 4000 x 4000
	// and Spawner is to be placed in any of corners of the floor surface
	// in order new location can be chosen correctly
	int MinSpawnLocation = 4000;
	int MaxSpawnLocation = 4000;
	int64 X = UKismetMathLibrary::RandomInteger64InRange(-MinSpawnLocation, MaxSpawnLocation);
	int64 Y = UKismetMathLibrary::RandomInteger64InRange(-MinSpawnLocation, MaxSpawnLocation);

	GetWorld()->SpawnActor<AFoodActor>(FoodActorToSpawn, FVector(X, Y, 0), FRotator(0, 0, 0));

}

