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


#include "GComponents/GCharacterStatsComponent.h"
#include "GComponents/GEventsComponent.h"
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


// Called when the game starts
void UGCharacterStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// Add this inside the BeginPlay function of the GStatsComponent
	UGEventsComponent* EventsComponent = Cast<UGEventsComponent>(GetOwner()->GetComponentByClass(UGEventsComponent::StaticClass()));
	if (EventsComponent)
	{
		EventsComponent->OnApplyItemStatModifiers.AddDynamic(this, &ThisClass::ApplyItemStatModifiers);
	}

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