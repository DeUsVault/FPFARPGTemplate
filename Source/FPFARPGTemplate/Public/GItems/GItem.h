// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GDataTypes/GDataTypes.h"
#include "GItem.generated.h"

// The UGItem class represents an in-game item, including its properties and functionality
UCLASS(BlueprintType, Blueprintable)
class FPFARPGTEMPLATE_API UGItem : public UObject
{
	GENERATED_BODY()

public:
	UGItem();

protected:
	// The name of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	FString Name;

	// A brief description of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	FString Description;

	// The icon representing the item in the game
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	UTexture2D* Icon;

	// An array of stat modifiers that the item applies when equipped
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	TArray<FGStatModifier> StatModifiers;

	// The item slot that the item can be equipped to
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	EGItemSlot ItemSlot;

public:
	// Getter for the item's name
	UFUNCTION(BlueprintPure, Category = "Item")
	FORCEINLINE FString GetName() const { return Name; }

	// Getter for the item's description
	UFUNCTION(BlueprintPure, Category = "Item")
	FORCEINLINE FString GetDescription() const { return Description; }

	// Getter for the item's icon
	UFUNCTION(BlueprintPure, Category = "Item")
	FORCEINLINE UTexture2D* GetIcon() const { return Icon; }

	// Getter for the item's stat modifiers
	UFUNCTION(BlueprintPure, Category = "Item")
	FORCEINLINE TArray<FGStatModifier> GetStatModifiers() const { return StatModifiers; }

	// Getter for the item's slot
	UFUNCTION(BlueprintPure, Category = "Item")
	FORCEINLINE EGItemSlot GetItemSlot() const { return ItemSlot; }
};
