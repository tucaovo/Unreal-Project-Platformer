// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeMover.h"
#include "Engine/World.h"

UCubeMover::UCubeMover()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCubeMover::BeginPlay()
{
	Super::BeginPlay();
	GetOwner()->GetRootComponent()->SetMobility(EComponentMobility::Movable);
	if (AxisToMove == 1) {
		InitialX = GetOwner()->GetActorLocation().Y;
	}
	else if (AxisToMove == 2)
	{
		InitialX = GetOwner()->GetActorLocation().Z;
	}
	else {
		InitialX = GetOwner()->GetActorLocation().X;
	}
}
void UCubeMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ShouldChangeDirection();
	MoveCube(DirectionX);
}

void UCubeMover::ShouldChangeDirection()
	{
	if (AxisToMove == 1) {
		CurrentX = GetOwner()->GetActorLocation().Y;
	}
	else if (AxisToMove == 2)
	{
		CurrentX = GetOwner()->GetActorLocation().Z;
	}
	else {
		CurrentX = GetOwner()->GetActorLocation().X;
	}
		if (CurrentX>InitialX + 80.f || CurrentX<InitialX - 80.f)
			DirectionX = -DirectionX;
	}

void UCubeMover::MoveCube(float Direction) {
	float Speed = 2.f;
	if (AxisToMove == 1) {
		FVector Movement = FVector(0.f, Direction * Speed, 0.f);
		GetOwner()->AddActorLocalOffset(Movement);
	}
	else if (AxisToMove == 2)
	{
		FVector Movement = FVector(0.f, 0.f, Direction * Speed);
		GetOwner()->AddActorLocalOffset(Movement);
	}
	else {
		FVector Movement = FVector(Direction * Speed, 0.f, 0.f);
		GetOwner()->AddActorLocalOffset(Movement);
	}
}

