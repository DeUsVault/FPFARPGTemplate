// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GAbility.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FPFARPGTEMPLATE_API UGAbility : public UObject
{
	GENERATED_BODY()

public:
	UGAbility();

	// Ability display name
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	FString DisplayName;

	// Ability cooldown in seconds
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ability")
	float Cooldown;

	// Whether the ability is currently on cooldown
	UPROPERTY(BlueprintReadOnly, Category = "Ability")
	bool bIsReady;

	// Owner character
	class ACharacter* OwningCharacter;

	// Activates the ability
	UFUNCTION(Category = "Ability")
	virtual void Activate();

	// Starts the cooldown timer
	void StartCooldown();

protected:
	// Handles cooldown timer expiration
	void CooldownTimerExpired();
};

