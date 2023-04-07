// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GDataTypes/GDataTypes.h"
#include "GCharacterStatsComponent.generated.h"

// The UGCharacterStatsComponent class represents the character stats system and its functionality
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPFARPGTEMPLATE_API UGCharacterStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGCharacterStatsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Modifies the base value of the specified stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ModifyBaseStatValue(FName StatName, float NewValue);
	// Modifies the current value of the specified stat
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ModifyCurrentStatValue(FName StatName, float NewValue);

	// Resets the current value of the specified stat to its base value
	UFUNCTION(BlueprintCallable, Category = "Stats")
	void ResetStatToBaseValue(FName StatName);

	// Gets the base value of the specified stat
	UFUNCTION(BlueprintCallable, Category = "Character Stats")
	float GetStatBaseValue(FName StatName) const;

	// Gets the current value of the specified stat
	UFUNCTION(BlueprintCallable, Category = "Character Stats")
	float GetStatCurrentValue(FName StatName) const;

	// Applies the stat modifiers from an item, either adding or removing them
	UFUNCTION(BlueprintCallable, Category = "Character Stats")
	void ApplyItemStatModifiers(class UGItem* Item, bool bAddModifiers);

	// Map containing the stats with FName as the key and FStat as the value
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats")
	TMap<FName, FGCharacterStat> Stats;

	// Reference to the data table containing stat information
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stats")
	UDataTable* StatDataTable;

private:
	// Loads the base stat data from the data table
	void LoadBaseStatData();
};
