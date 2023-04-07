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
#include "GInventoryComponent.generated.h"

// The UGInventoryComponent class represents the inventory system and its functionality
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPFARPGTEMPLATE_API UGInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Maximum inventory capacity
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory")
	int32 MaxInventoryCapacity;

	// Items in the inventory
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<class UGItem*> InventoryItems;

	// Equipment slots
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
	TMap<EGItemSlot, UGItem*> EquippedItems;

	// Function to add an item to the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UGItem* Item);

	// Function to remove an item from the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void RemoveItem(UGItem* Item);

	// Function to equip an item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool EquipItem(UGItem* Item);

	// Function to unequip an item
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool UnequipItem(EGItemSlot EquipmentSlot);

	// TMap containing the currencies with FName as the key and FGCurrency as the value
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Currency")
	TMap<FName, FGCurrency> Currencies;

	// Reference to the data table containing currency information
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Currency")
	UDataTable* CurrencyDataTable;

	// Function to add currency to the inventory
	UFUNCTION(BlueprintCallable, Category = "Currency")
	void AddCurrency(FName CurrencyName, int32 Amount);

	// Function to remove currency from the inventory
	UFUNCTION(BlueprintCallable, Category = "Currency")
	void RemoveCurrency(FName CurrencyName, int32 Amount);

	// Function to get the current amount of a specific currency
	UFUNCTION(BlueprintCallable, Category = "Currency")
	int32 GetCurrencyAmount(FName CurrencyName) const;

private:
	// Helper function to check if the inventory is full
	bool IsInventoryFull() const;

	// Loads the base currency data from the data table
	void LoadBaseCurrencyData();
};
