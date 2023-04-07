#pragma once

#include "Engine/DataTable.h"
#include "GDataTypes.generated.h"


// Enumeration representing the different item slots
UENUM(BlueprintType)
enum class EGItemSlot : uint8
{
	EGIT_None UMETA(DisplayName = "None"),
	EGIT_Head UMETA(DisplayName = "Head"),
	EGIT_Chest UMETA(DisplayName = "Chest"),
	EGIT_Legs UMETA(DisplayName = "Legs"),
	EGIT_Feet UMETA(DisplayName = "Feet"),
	EGIT_Hands UMETA(DisplayName = "Hands"),
	EGIT_Weapon UMETA(DisplayName = "Weapon"),

	EGIT_MAX UMETA(DisplayName = "DefaultMax")
};


// Enumeration representing the different types of stat modifiers
UENUM(BlueprintType)
enum class EGStatModifierType : uint8
{
	Additive,
	Multiplicative,
};


// Struct representing a single stat modifier
USTRUCT(BlueprintType)
struct FGStatModifier
{
	GENERATED_BODY()

	// The name of the stat to be modified
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	FName StatName;

	// The type of modifier: additive or multiplicative
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	EGStatModifierType ModifierType;

	// The value of the modifier
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stat Modifier")
	float Value;
};


// Struct representing a character stat, to be used in a data table
USTRUCT(BlueprintType)
struct FGCharacterStat : public FTableRowBase
{
	GENERATED_BODY()

	// The base value of the stat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseValue;

	// The modified base value of the stat after applying item modifiers
	UPROPERTY(BlueprintReadOnly)
	float ModifiedBaseValue;

	// The current value of the stat
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CurrentValue;
};

USTRUCT(BlueprintType)
struct FGCurrency : public FTableRowBase
{
	GENERATED_BODY()

	// The name of the currency
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FName CurrencyName;

	// The display name of the currency
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FText DisplayName;

	// The icon representing the currency
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UTexture2D* Icon;

	// The amount of the currency
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Amount;
};

UENUM(BlueprintType)
enum class EFaction : uint8
{
	FACTION_A,
	FACTION_B,
	FACTION_C
};
