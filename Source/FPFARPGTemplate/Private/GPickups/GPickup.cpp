// Fill out your copyright notice in the Description page of Project Settings.


#include "GPickups/GPickup.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AGPickup::AGPickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
}

// Called when the game starts or when spawned
void AGPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

