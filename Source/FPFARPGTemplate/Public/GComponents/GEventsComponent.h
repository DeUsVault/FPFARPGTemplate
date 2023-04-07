// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GEventsComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, DamageAmount);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FApplyItemStatModifiersDelegate, class UGItem*, Item, bool, bAddModifiers);


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddItemDelegate, class UGItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemoveItemDelegate, class UGItem*, Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAddCurrencyDelegate, FName, CurrencyName, int32, Amount);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRemoveCurrencyDelegate, FName, CurrencyName, int32, Amount);



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

		
};
