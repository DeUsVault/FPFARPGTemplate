// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GPickups/GPickup.h"
#include "GPickup_Item.generated.h"

/**
 * 
 */
UCLASS()
class FPFARPGTEMPLATE_API AGPickup_Item : public AGPickup
{
	GENERATED_BODY()
	
public:
	AGPickup_Item();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	class UGItem* Item;
};
