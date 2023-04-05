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

};
