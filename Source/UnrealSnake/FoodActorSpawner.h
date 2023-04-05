// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "FoodActor.h"

#include "FoodActorSpawner.generated.h"

UCLASS()
class UNREALSNAKE_API AFoodActorSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFoodActorSpawner();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorToSpawn")
		TSubclassOf<AFoodActor> FoodActorToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
