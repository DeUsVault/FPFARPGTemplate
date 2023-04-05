// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GCharacterProgressionComponent.h"

// Sets default values for this component's properties
UGCharacterProgressionComponent::UGCharacterProgressionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	PrimaryComponentTick.bCanEverTick = false;
	CurrentLevel = 1;
	MaxLevel = 100;
	CurrentXP = 0.0f;
	XPToNextLevel = 100.0f;
	AbilityPoints = 0;
	// ...
}


// Called when the game starts
void UGCharacterProgressionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGCharacterProgressionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Add experience points to the character
void UGCharacterProgressionComponent::AddXP(float XP)
{
	CurrentXP += XP;

	if (CurrentXP >= XPToNextLevel && CurrentLevel < MaxLevel)
	{
		LevelUp();
	}
}

// Level up the character and reset XP to 0
void UGCharacterProgressionComponent::LevelUp()
{
	CurrentLevel++;
	CurrentXP = 0.0f;
	AbilityPoints++;

	CalculateXPToNextLevel();
}

// Spend an ability point if available
void UGCharacterProgressionComponent::SpendAbilityPoint()
{
	if (AbilityPoints > 0)
	{
		AbilityPoints--;
	}
}

// Calculate the experience points required for the next level using a custom formula
void UGCharacterProgressionComponent::CalculateXPToNextLevel()
{
	XPToNextLevel = 100.0f * FMath::Pow(1.1f, CurrentLevel);
}