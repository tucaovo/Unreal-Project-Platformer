// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGame.h"

AEndGame::AEndGame() {
	OnActorBeginOverlap.AddDynamic(this,&AEndGame::Event);
}

void AEndGame::BeginPlay() {
	Super::BeginPlay();
}

void AEndGame::Event(class AActor* overlappedActor, AActor* OtherActor) {
	OtherActor->SetActorLocation(PlayerStart->GetActorLocation());
}
