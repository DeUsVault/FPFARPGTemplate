// Fill out your copyright notice in the Description page of Project Settings.


#include "GPickups/GPickup_Currency.h"
#include "GComponents/GEventsComponent.h"
#include "GameFramework/Character.h"

AGPickup_Currency::AGPickup_Currency()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGPickup_Currency::OnPickedUp(ACharacter* Character)
{
	if (Character)
	{
		UGEventsComponent* EventsComponent = Cast<UGEventsComponent>(Character->GetComponentByClass(UGEventsComponent::StaticClass()));
		if (EventsComponent)
		{
			// Call the OnAddCurrency delegate using the EventsComponent
			EventsComponent->OnAddCurrency.Broadcast(CurrencyName, Amount);
		}
	}

	// Call the base class implementation to handle any common functionality
	Super::OnPickedUp(Character);
}