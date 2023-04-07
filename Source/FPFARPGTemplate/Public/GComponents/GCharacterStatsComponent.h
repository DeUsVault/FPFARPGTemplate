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

	UFUNCTION()
	void UpdateAllStats();

	FTimerHandle InitialStatUpdateTimer;

};
