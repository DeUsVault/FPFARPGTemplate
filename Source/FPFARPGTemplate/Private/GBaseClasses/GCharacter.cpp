// Fill out your copyright notice in the Description page of Project Settings.


#include "GBaseClasses/GCharacter.h"
#include "GComponents/GEventsComponent.h"

// Sets default values
AGCharacter::AGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EventsComponent = CreateDefaultSubobject<UGEventsComponent>(TEXT("EventsComponent"));
}

// Called when the game starts or when spawned
void AGCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

