// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GInventoryComponent.h"
#include "GComponents/GCharacterStatsComponent.h"
#include "GItems/GItem.h"

// Sets default values for this component's properties
UGInventoryComponent::UGInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	MaxInventoryCapacity = 30;

	LoadBaseCurrencyData();
	// ...
}


// Called when the game starts
void UGInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UGInventoryComponent::AddItem(UGItem* Item)
{
	if (IsInventoryFull())
	{
		return false;
	}

	InventoryItems.Add(Item);
	return true;
}

bool UGInventoryComponent::RemoveItem(UGItem* Item)
{
	return InventoryItems.Remove(Item) > 0;
}

bool UGInventoryComponent::EquipItem(UGItem* Item)
{
	if (!Item)
	{
		return false;
	}

	EGItemSlot EquipmentSlot = Item->GetItemSlot();

	// Check if an item is already equipped in the same slot, and unequip it if so
	if (EquippedItems.Contains(EquipmentSlot))
	{
		if (!UnequipItem(EquipmentSlot))
		{
			return false;
		}
	}

	EquippedItems.Add(EquipmentSlot, Item);
	RemoveItem(Item);

	UGCharacterStatsComponent* StatsComponent = GetOwner()->FindComponentByClass<UGCharacterStatsComponent>();
	if (StatsComponent)
	{
		StatsComponent->ApplyItemStatModifiers(Item, true);
	}

	return true;
}


bool UGInventoryComponent::UnequipItem(EGItemSlot EquipmentSlot)
{
	UGItem** FoundItem = EquippedItems.Find(EquipmentSlot);
	if (!FoundItem || IsInventoryFull())
	{
		return false;
	}

	UGItem* Item = *FoundItem;
	EquippedItems.Remove(EquipmentSlot);
	AddItem(Item);

	UGCharacterStatsComponent* StatsComponent = GetOwner()->FindComponentByClass<UGCharacterStatsComponent>();
	if (StatsComponent)
	{
		StatsComponent->ApplyItemStatModifiers(Item, false);
	}

	return true;
}

bool UGInventoryComponent::IsInventoryFull() const
{
	return InventoryItems.Num() >= MaxInventoryCapacity;
}


void UGInventoryComponent::AddCurrency(FName CurrencyName, int32 Amount)
{
	if (Amount > 0)
	{
		FGCurrency* Currency = Currencies.Find(CurrencyName);
		if (Currency)
		{
			Currency->Amount += Amount;
		}
		else
		{
			// Will crash if currency isn't in the datatable
			FGCurrency NewCurrency = *CurrencyDataTable->FindRow<FGCurrency>(CurrencyName, FString());
			NewCurrency.Amount = Amount;
			Currencies.Add(CurrencyName, NewCurrency);
		}
	}
}


bool UGInventoryComponent::RemoveCurrency(FName CurrencyName, int32 Amount)
{
	FGCurrency* Currency = Currencies.Find(CurrencyName);
	if (Currency && Currency->Amount >= Amount && Amount > 0)
	{
		Currency->Amount -= Amount;
		return true;
	}
	return false;
}


int32 UGInventoryComponent::GetCurrencyAmount(FName CurrencyName) const
{
	const FGCurrency* Currency = Currencies.Find(CurrencyName);
	if (Currency)
	{
		return Currency->Amount;
	}
	return 0;
}


void UGInventoryComponent::LoadBaseCurrencyData()
{
	if (CurrencyDataTable)
	{
		TArray<FGCurrency*> AllCurrencies;
		CurrencyDataTable->GetAllRows<FGCurrency>(FString(), AllCurrencies);

		for (FGCurrency* CurrencyData : AllCurrencies)
		{
			if (CurrencyData)
			{
				FGCurrency NewCurrency = *CurrencyData;
				NewCurrency.Amount = 0;
				Currencies.Add(NewCurrency.CurrencyName, NewCurrency);
			}
		}
	}
}