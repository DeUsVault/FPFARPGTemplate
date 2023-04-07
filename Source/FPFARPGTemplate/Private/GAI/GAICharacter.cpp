// Fill out your copyright notice in the Description page of Project Settings.


#include "GAI/GAICharacter.h"
#include "GComponents/GCharacterInfoComponent.h"

// Sets default values
AGAICharacter::AGAICharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CharacterInfoComponent = CreateDefaultSubobject<UGCharacterInfoComponent>(TEXT("CharacterInfoComponent"));

}

// Called when the game starts or when spawned
void AGAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

