// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GPickupComponent.h"
#include "GPickups/GPickup_Item.h"
#include "GPickups/GPickup_Currency.h"
#include "GComponents/GInventoryComponent.h"

// Sets default values for this component's properties
UGPickupComponent::UGPickupComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UGPickupComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGPickupComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGPickupComponent::PickupItem(AGPickup_Item* ItemPickup)
{
	if (!ItemPickup)
	{
		return;
	}

	UGInventoryComponent* InventoryComponent = GetOwner()->FindComponentByClass<UGInventoryComponent>();
	if (InventoryComponent)
	{
		if (InventoryComponent->AddItem(ItemPickup->Item))
		{
			ItemPickup->Destroy();
		}
	}
}

void UGPickupComponent::PickupCurrency(AGPickup_Currency* CurrencyPickup)
{
	if (!CurrencyPickup)
	{
		return;
	}

	UGInventoryComponent* InventoryComponent = GetOwner()->FindComponentByClass<UGInventoryComponent>();
	if (InventoryComponent)
	{
		InventoryComponent->AddCurrency(CurrencyPickup->CurrencyName, CurrencyPickup->Amount);
		CurrencyPickup->Destroy();
	}
}