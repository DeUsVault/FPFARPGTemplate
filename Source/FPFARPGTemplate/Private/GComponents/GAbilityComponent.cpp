// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GAbilityComponent.h"
#include "GAbilities/GAbility.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UGAbilityComponent::UGAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UGAbilityComponent::BeginPlay()
{
	Super::BeginPlay();

	LoadAbilities();
	// ...
	
}


// Called every frame
void UGAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Activates the ability at the specified index
void UGAbilityComponent::ActivateAbilityBySlot(int32 Index)
{
	if (Abilities.IsValidIndex(Index))
	{
		UGAbility* Ability = Abilities[Index];
		if (Ability)
		{
			Ability->Activate();
		}
	}
}


void UGAbilityComponent::LoadAbilities()
{
	Abilities.Empty();

	for (TSubclassOf<UGAbility>& AbilityClass : AbilityClasses)
	{
		if (AbilityClass)
		{
			UGAbility* AbilityInstance = NewObject<UGAbility>(this, AbilityClass);
			if (AbilityInstance)
			{
				AbilityInstance->OwningCharacter = Cast<ACharacter>(GetOwner());
				Abilities.Add(AbilityInstance);
			}
		}
	}
}
