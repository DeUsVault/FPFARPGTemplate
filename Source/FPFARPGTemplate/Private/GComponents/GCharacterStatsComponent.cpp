// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GCharacterStatsComponent.h"
#include "GItems/GItem.h"

// Sets default values for this component's properties
UGCharacterStatsComponent::UGCharacterStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Load stats from the data table
	LoadBaseStatData();
	// ...
}

void UGCharacterStatsComponent::ModifyBaseStatValue(FName StatName, float NewValue)
{
	if (Stats.Contains(StatName))
	{
		Stats[StatName].BaseValue = NewValue;
	}
}

void UGCharacterStatsComponent::ModifyCurrentStatValue(FName StatName, float NewValue)
{
	if (Stats.Contains(StatName))
	{
		Stats[StatName].CurrentValue = NewValue;
	}
}

void UGCharacterStatsComponent::ResetStatToBaseValue(FName StatName)
{
	if (Stats.Contains(StatName))
	{
		Stats[StatName].CurrentValue = Stats[StatName].BaseValue;
	}
}

float UGCharacterStatsComponent::GetStatBaseValue(FName StatName) const
{
	const FGCharacterStat* Stat = Stats.Find(StatName);
	if (Stat)
	{
		return Stat->BaseValue;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Stat not found: %s"), *StatName.ToString());
		return 0.0f;
	}
}

float UGCharacterStatsComponent::GetStatCurrentValue(FName StatName) const
{
	const FGCharacterStat* Stat = Stats.Find(StatName);
	if (Stat)
	{
		return Stat->CurrentValue;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Stat not found: %s"), *StatName.ToString());
		return 0.0f;
	}
}

void UGCharacterStatsComponent::ApplyItemStatModifiers(UGItem* Item, bool bAddModifiers)
{
	if (!Item || !Item->IsValidLowLevel())
	{
		return;
	}

	const TArray<FGStatModifier>& Modifiers = Item->GetStatModifiers();
	for (const FGStatModifier& Modifier : Modifiers)
	{
		FGCharacterStat* Stat = Stats.Find(Modifier.StatName);
		if (Stat)
		{
			if (Modifier.ModifierType == EGStatModifierType::Additive)
			{
				if (bAddModifiers)
				{
					Stat->ModifiedBaseValue += Modifier.Value;
				}
				else
				{
					Stat->ModifiedBaseValue -= Modifier.Value;
				}
			}
			else
			{
				if (bAddModifiers)
				{
					Stat->ModifiedBaseValue *= (1.0f + Modifier.Value);
				}
				else
				{
					Stat->ModifiedBaseValue /= (1.0f + Modifier.Value);
				}
			}
			// Update the current value to be in sync with the modified base value
			Stat->CurrentValue = Stat->ModifiedBaseValue;
		}
	}
}


void UGCharacterStatsComponent::LoadBaseStatData()
{
	if (StatDataTable)
	{
		TArray<FName> RowNames = StatDataTable->GetRowNames();
		for (FName RowName : RowNames)
		{
			FGCharacterStat* StatRow = StatDataTable->FindRow<FGCharacterStat>(RowName, FString(), false);
			if (StatRow)
			{
				FGCharacterStat NewStat;
				NewStat.BaseValue = StatRow->BaseValue;
				NewStat.CurrentValue = StatRow->CurrentValue;
				Stats.Add(RowName, NewStat);
			}
		}
	}
}