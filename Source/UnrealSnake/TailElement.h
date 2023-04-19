// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TailElement.generated.h"

UCLASS()
class UNREALSNAKE_API ATailElement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATailElement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* TailStaticMeshComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare overlap begin function
	UFUNCTION()
		void OnTailOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
