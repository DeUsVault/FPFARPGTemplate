// Copyright (c) 2023 Full Power Fantasy LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
