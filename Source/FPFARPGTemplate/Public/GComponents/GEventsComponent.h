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
#include "GEventsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, DamageAmount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FApplyItemStatModifiersDelegate, class UGItem*, Item, bool, bAddModifiers);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddItemDelegate, class UGItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveItemDelegate, class UGItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAddCurrencyDelegate, FName, CurrencyName, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRemoveCurrencyDelegate, FName, CurrencyName, int32, Amount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnStatChangedDelegate, const FGCharacterStat&, Stat);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquipped, class AGWeapon*, Weapon);




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGEventsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGEventsComponent();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDamageTaken OnDamageTaken;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FApplyItemStatModifiersDelegate OnApplyItemStatModifiers;


	UPROPERTY(BlueprintAssignable, Category = "Events")
	FAddItemDelegate OnAddItem;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FRemoveItemDelegate OnRemoveItem;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FAddCurrencyDelegate OnAddCurrency;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FRemoveCurrencyDelegate OnRemoveCurrency;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnStatChangedDelegate OnStatChanged;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnWeaponEquipped OnWeaponEquipped;
		
};
