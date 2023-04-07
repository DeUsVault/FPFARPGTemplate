// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GCharacterInfoComponent.h"

// Sets default values for this component's properties
UGCharacterInfoComponent::UGCharacterInfoComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UGCharacterInfoComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGCharacterInfoComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGCharacterInfoComponent::IsHostileTo(const UGCharacterInfoComponent* OtherCharacterInfo) const
{
	if (!OtherCharacterInfo)
	{
		return false;
	}

	// Compare the factions of the characters
	// Replace this logic with your specific faction hostility rules
	if (Faction == OtherCharacterInfo->Faction)
	{
		return false;
	}
	else
	{
		return true;
	}
}

