// Fill out your copyright notice in the Description page of Project Settings.

#include "FoodActor.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakePawn.h"

// Sets default values
AFoodActor::AFoodActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FoodMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodMeshComponent"));
	SetRootComponent(FoodMeshComponent);
	FoodMeshComponent->SetGenerateOverlapEvents(true);
	FoodMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AFoodActor::OnFoodOverlapBegin);
}

// Called when the game starts or when spawned
void AFoodActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFoodActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodActor::OnFoodOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherActor->ActorHasTag("SnakeHead"))
	{
		Cast<ASnakePawn>(OtherActor)->EatFood();
		Destroy();
	}
}
