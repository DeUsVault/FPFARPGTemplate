// Fill out your copyright notice in the Description page of Project Settings.


#include "GPickups/GPickup_Item.h"
#include "GComponents/GEventsComponent.h"
#include "GameFramework/Character.h"

AGPickup_Item::AGPickup_Item()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AGPickup_Item::OnPickedUp(ACharacter* Character)
{
	if (Character)
	{
		UGEventsComponent* EventsComponent = Cast<UGEventsComponent>(Character->GetComponentByClass(UGEventsComponent::StaticClass()));
		if (EventsComponent)
		{
			// Call the OnAddItem delegate using the EventsComponent
			EventsComponent->OnAddItem.Broadcast(Item);
		}
	}

	// Call the base class implementation to handle any common functionality
	Super::OnPickedUp(Character);
}