// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GCharacterInputComponent.h"
#include "GComponents/GCameraComponent.h"
#include "GComponents/GAbilityComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "Components/InputComponent.h"

// Sets default values for this component's properties
UGCharacterInputComponent::UGCharacterInputComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGCharacterInputComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Character = Cast<ACharacter>(GetOwner());
}


// Called every frame
void UGCharacterInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check if the character is valid
	if (Character)
	{
		// Get the player controller
		APlayerController* PC = Cast<APlayerController>(Character->GetController());
		if (PC)
		{
			// Get the hit result under the mouse cursor
			FHitResult HitResult;
			if (PC->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, HitResult))
			{
				// Calculate the rotation from the character to the world mouse location
				FVector WorldMouseLocation = HitResult.Location;
				FVector CharacterLocation = Character->GetActorLocation();
				WorldMouseLocation.Z = CharacterLocation.Z;

				FRotator LookRotation = UKismetMathLibrary::FindLookAtRotation(CharacterLocation, WorldMouseLocation);
				// Set the control rotation to face the world mouse location
				PC->SetControlRotation(LookRotation);
			}
		}
	}
}


// Set up the input component and bind the required inputs
void UGCharacterInputComponent::SetupInputComponent(UInputComponent* InputComponent)
{
	check(InputComponent);

	// Bind movement input
	InputComponent->BindAxis("MoveForward", this, &UGCharacterInputComponent::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &UGCharacterInputComponent::MoveRight);

	// Bind turn input
	//InputComponent->BindAxis("Turn", this, &UGCharacterInputComponent::Turn);

	// Bind attack input
	InputComponent->BindAction("ActivateAbilitySlot1", IE_Pressed, this, &UGCharacterInputComponent::ActivateAbilitySlot1);
	InputComponent->BindAction("ActivateAbilitySlot2", IE_Pressed, this, &UGCharacterInputComponent::ActivateAbilitySlot2);
	InputComponent->BindAction("ActivateAbilitySlot3", IE_Pressed, this, &UGCharacterInputComponent::ActivateAbilitySlot3);
	InputComponent->BindAction("ActivateAbilitySlot4", IE_Pressed, this, &UGCharacterInputComponent::ActivateAbilitySlot4);

	// Bind jump input
	InputComponent->BindAction("Jump", IE_Pressed, this, &UGCharacterInputComponent::Jump);
}


// Move the character forward based on input value
void UGCharacterInputComponent::MoveForward(float AxisValue)
{
	if (AxisValue != 0.0f && Character)
	{
		// Find the camera component and get the forward vector
		UGCameraComponent* CameraComponent = Character->FindComponentByClass<UGCameraComponent>();
		if (CameraComponent)
		{
			FVector Forward = CameraComponent->GetForwardVector();
			Forward.Z = 0.0f;
			Forward.Normalize();
			// Apply movement input in the forward direction
			Character->AddMovementInput(Forward, AxisValue);
		}
	}
}


// Move the character to the right based on input value
void UGCharacterInputComponent::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0f && Character)
	{
		// Find the camera component and get the right vector
		UGCameraComponent* CameraComponent = Character->FindComponentByClass<UGCameraComponent>();
		if (CameraComponent)
		{
			FVector Right = CameraComponent->GetRightVector();
			Right.Z = 0.0f;
			Right.Normalize();
			// Apply movement input in the right direction
			Character->AddMovementInput(Right, AxisValue);
		}
	}
}


// Rotate the character
void UGCharacterInputComponent::Turn(float AxisValue)
{
	
	/*if (Character)
	{
		Character->AddControllerYawInput(AxisValue);
	}*/
}

void UGCharacterInputComponent::ActivateAbilitySlot1()
{
	// Get the character owner
	ACharacter* OwningCharacter = Cast<ACharacter>(GetOwner());
	if (OwningCharacter)
	{
		// Get the ability component
		UGAbilityComponent* AbilityComponent = OwningCharacter->FindComponentByClass<UGAbilityComponent>();
		if (AbilityComponent)
		{
			// Activate the ability in slot 1 (slot index 0)
			AbilityComponent->ActivateAbilityBySlot(0);
		}
	}
}

void UGCharacterInputComponent::ActivateAbilitySlot2()
{
	// Implement functionality to activate ability in slot 2
}

void UGCharacterInputComponent::ActivateAbilitySlot3()
{
	// Implement functionality to activate ability in slot 3
}

void UGCharacterInputComponent::ActivateAbilitySlot4()
{
	// Implement functionality to activate ability in slot 4
}

void UGCharacterInputComponent::Jump()
{
	// Implement character jump functionality
}
