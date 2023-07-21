// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CubeMover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class P1_MOVINGCUBE_API UCubeMover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCubeMover();
	void MoveCube(float Direction);
	float DirectionX = 1.f;
	float InitialX, CurrentX;
	void ShouldChangeDirection();
	UPROPERTY(EditAnywhere)
		int AxisToMove; // X is 0, Y = 1, Z = 2
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
