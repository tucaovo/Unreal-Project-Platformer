// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "Engine/TriggerBox.h"
#include "GameFramework/PlayerStart.h"
#include "EndGame.generated.h"

/**
 * 
 */
UCLASS()
class P1_MOVINGCUBE_API AEndGame : public ATriggerBox
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay();
public:
	AEndGame();
	UPROPERTY(EditAnywhere, Category=Spawn)
		APlayerStart* PlayerStart;
	UFUNCTION()
		void Event(class AActor* overlappedActor, class AActor* OtherActor);
		
};
