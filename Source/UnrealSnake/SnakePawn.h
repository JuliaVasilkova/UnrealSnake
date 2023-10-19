// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SnakePawn.generated.h"

class TailElement;

UCLASS()
class UNREALSNAKE_API ASnakePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASnakePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCapsuleComponent* CapsuleComponent;

	// Camera component setup
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* SphereStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class UFloatingPawnMovement* MoveComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SnakePawnLogic")
		int32 Scores =  0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SnakePawnLogic")
		bool ShouldRestart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		TSubclassOf<class ATailElement> TailElementToSpawn;

	// All the elements in snake's tail
	TArray<class ATailElement*> TailElements;

	//Size of step for snake movement
	int32 StepSize = 100;

	bool isFirst = true;

	FTransform LastAddedTransform;

	class ATailElement* LastAddedElement = NULL;

	FVector SnakePrevLocation;

	// For moving tail elements
	mutable FCriticalSection TailMovementCriticalSection;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateScores();

	UFUNCTION(BlueprintCallable)
	int32 GetScores();

	// declare overlap begin function
	UFUNCTION()
	void OnTailOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void EatFood();

	void AddTailElement();

	void MoveTail();

	void DeleteTail();
};
