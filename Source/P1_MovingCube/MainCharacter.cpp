// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/LocalPlayer.h"
#include "InputActionValue.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "Engine/TriggerBox.h"
#include "EnhancedInputSubsystems.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (UGameplayStatics::GetPlayerController(this, 0))//maybe I should get the Controller first and then cast a PlayerController to it ?
	{
		PlayerController = UGameplayStatics::GetPlayerController(this, 0);
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(CubeMappingContext, 0);
		}
	}
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(MoveForwardAction, ETriggerEvent::Triggered, this, &AMainCharacter::MoveForward);
		EnhancedInputComponent->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &AMainCharacter::MoveRight);
		EnhancedInputComponent->BindAction(YawRotation, ETriggerEvent::Triggered, this, &AMainCharacter::RotateYaw);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Ongoing, this, &AMainCharacter::Jump);
		EnhancedInputComponent->BindAction(PitchRotation, ETriggerEvent::Triggered, this, &AMainCharacter::RotatePitch);
	}
}

void AMainCharacter::MoveForward(const FInputActionValue& Value) {
	const float DirectionValue=Value.Get<float>();//<-------MODIFY IT TO VECTOR 2D TO MERGE THE 2 IAs INTO ONE
	if (DirectionValue && Controller)
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward, DirectionValue);// did a new Move right and forward and handle just 2 inputs per IA 
	}
}

void AMainCharacter::MoveRight(const  FInputActionValue& Value) {
	const float DirectionValue = Value.Get<float>();
	if (DirectionValue && Controller) {
		FVector Forward = GetActorRightVector();
		AddMovementInput(Forward, DirectionValue);
	}
}

void AMainCharacter::RotateYaw(const FInputActionValue& Value) {
	const float Rotation = Value.Get<float>();
	if(Rotation && Controller){ 
		AddControllerYawInput(Rotation);
	}
}
void AMainCharacter::RotatePitch(const FInputActionValue& Value) {
	const float Rotation = Value.Get<float>();
	if (Rotation)
	{
		AddControllerPitchInput(Rotation);
	}
}
