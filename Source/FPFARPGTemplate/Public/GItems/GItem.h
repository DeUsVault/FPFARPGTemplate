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
