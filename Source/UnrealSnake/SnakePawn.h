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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		int32 Scores =  0;

	// All the elements in snake's tail
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		TArray<ATailElement*> TailElements;
	//Size of step for snake movement
	int32 StepSize = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		bool isFirst = true;

	// Location of last added tail element
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		FTransform LastAddedTransform;

	// Location of last added tail element
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		ATailElement* LastAddedElement = NULL;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TailElementsLogic")
		TSubclassOf<ATailElement> TailElementToSpawn;

	// Location of last added tail element
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "TailMovementLogic")
		FVector SnakePrevLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable)
	void UpdateScores();

	UFUNCTION(BlueprintCallable)
	int32 GetScores();

	void EatFood();

	void AddTailElement();

	void MoveTail();
};
