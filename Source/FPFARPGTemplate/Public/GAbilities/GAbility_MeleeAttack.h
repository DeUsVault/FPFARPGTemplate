// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GAbilities/GAbility.h"
#include "GAbility_MeleeAttack.generated.h"

/**
 * UGMeleeAttackAbility class represents a melee attack ability in the game.
 * It inherits from the base UGAbility class.
 */
UCLASS(Blueprintable)
class FPFARPGTEMPLATE_API UGAbility_MeleeAttack : public UGAbility
{
	GENERATED_BODY()

public:
	// Overrides the Activate function from the base UGAbility class.
	virtual void Activate() override;

	// Function to perform a cone trace for the melee attack.
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void PerformConeTrace();

	// The range of the melee attack ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cone Trace")
	float AbilityRange;

	// The angle of the cone used for the melee attack ability trace.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cone Trace")
	float AbilityConeAngle;

	// The damage dealt by the melee attack ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cone Trace")
	float AbilityDamage;

	// The animation to play when the ability is activated.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
	class UAnimMontage* AbilityAnimation;

	// The damage type to use for the melee attack ability.
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cone Trace")
	TSubclassOf<UDamageType> DamageTypeClass = UDamageType::StaticClass();
};
