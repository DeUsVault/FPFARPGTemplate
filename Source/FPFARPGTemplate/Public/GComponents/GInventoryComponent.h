// Fill out your copyright notice in the Description page of Project Settings.

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
	bool AddItem(UGItem* Item);

	// Function to remove an item from the inventory
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool RemoveItem(UGItem* Item);

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
	bool RemoveCurrency(FName CurrencyName, int32 Amount);

	// Function to get the current amount of a specific currency
	UFUNCTION(BlueprintCallable, Category = "Currency")
	int32 GetCurrencyAmount(FName CurrencyName) const;

private:
	// Helper function to check if the inventory is full
	bool IsInventoryFull() const;

	// Loads the base currency data from the data table
	void LoadBaseCurrencyData();
};
