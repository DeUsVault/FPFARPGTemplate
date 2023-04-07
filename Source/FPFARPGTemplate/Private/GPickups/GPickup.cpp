// Fill out your copyright notice in the Description page of Project Settings.


#include "GPickups/GPickup.h"
#include "GComponents/GEventsComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"

AGPickup::AGPickup()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionSphere"));
	CollisionSphere->SetupAttachment(Mesh);
	CollisionSphere->SetCollisionProfileName("OverlapOnlyPawn");
}

void AGPickup::BeginPlay()
{
	Super::BeginPlay();
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AGPickup::OnOverlapBegin);
}

void AGPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGPickup::OnPickedUp(ACharacter* Character)
{
	if (Character)
	{
		UGEventsComponent* EventsComponent = Cast<UGEventsComponent>(Character->GetComponentByClass(UGEventsComponent::StaticClass()));
		if (EventsComponent)
		{
			// Call the appropriate delegate for the pickup type (item or currency) using the EventsComponent
			// For example:
			// EventsComponent->OnAddItem.Broadcast(Item);
			// EventsComponent->OnAddCurrency.Broadcast(CurrencyName, Amount);
		}
	}
}

void AGPickup::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		OnPickedUp(Character);
		Destroy();
	}
}