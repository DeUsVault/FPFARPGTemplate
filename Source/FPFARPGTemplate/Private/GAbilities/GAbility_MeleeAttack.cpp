// Fill out your copyright notice in the Description page of Project Settings.


#include "GAbilities/GAbility_MeleeAttack.h"
#include "GComponents/GAbilityComponent.h"
#include "GHelpers/GTraceHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"

void UGAbility_MeleeAttack::Activate()
{
	Super::Activate();

	// Find the ability component on the owning character
	UGAbilityComponent* AbilityComponent = OwningCharacter->FindComponentByClass<UGAbilityComponent>();
	if (AbilityComponent)
	{
		// Bind the PerformConeTrace function to the OnEndAbilityNotify delegate
		AbilityComponent->OnEndAbilityNotify.AddDynamic(this, &UGAbility_MeleeAttack::PerformConeTrace);
	}

	// Play the ability animation if it's set and the owning character is valid
	if (OwningCharacter && AbilityAnimation)
	{
		OwningCharacter->PlayAnimMontage(AbilityAnimation);
	}
}

void UGAbility_MeleeAttack::PerformConeTrace()
{
	// Implement the cone trace logic using GTraceHelper
	if (OwningCharacter)
	{
		FVector Start = OwningCharacter->GetActorLocation();
		FVector Direction = OwningCharacter->GetActorForwardVector();
		int32 NumRays = 10;
		TArray<FHitResult> HitResults;

		// Perform the cone trace
		UGTraceHelpers::PerformConeTrace(GetWorld(), OwningCharacter, Start, Direction, AbilityRange, AbilityConeAngle, NumRays, HitResults);

		// Process HitResults array
		for (const FHitResult& HitResult : HitResults)
		{
			AActor* HitActor = HitResult.GetActor();
			if (HitActor)
			{
				// Apply damage to the hit actor
				UGameplayStatics::ApplyDamage(HitActor, AbilityDamage, OwningCharacter->GetController(), OwningCharacter, DamageTypeClass);
			}
		}
	}
	// Get the AbilityComponent
	UGAbilityComponent* AbilityComponent = OwningCharacter->FindComponentByClass<UGAbilityComponent>();

	// Clear the delegate bindings
	if (AbilityComponent)
	{
		AbilityComponent->OnEndAbilityNotify.Clear();
	}
}

