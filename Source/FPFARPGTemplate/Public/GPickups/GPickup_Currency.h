// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPickups/GPickup.h"
#include "GPickup_Currency.generated.h"

/**
 * 
 */
UCLASS()
class FPFARPGTEMPLATE_API AGPickup_Currency : public AGPickup
{
	GENERATED_BODY()
	
public:
	AGPickup_Currency();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Currency")
	FName CurrencyName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Currency")
	int32 Amount;

protected:
	// Called when the currency pickup is collected
	virtual void OnPickedUp(class ACharacter* Character) override;
};