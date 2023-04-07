// Fill out your copyright notice in the Description page of Project Settings.


#include "GPlayer/GPlayerCharacter.h"
#include "GComponents/GCharacterInputComponent.h"
#include "GComponents/GCameraComponent.h"
#include "GComponents/GInventoryComponent.h"
#include "GComponents/GCharacterStatsComponent.h"
#include "GComponents/GAbilityComponent.h"
#include "GComponents/GDialogueComponent.h"
#include "GComponents/GCharacterProgressionComponent.h"
#include "GComponents/GCharacterInfoComponent.h"

// Sets default values
AGPlayerCharacter::AGPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Initialize components
	CharacterInputComponent = CreateDefaultSubobject<UGCharacterInputComponent>(TEXT("CharacterInputComponent"));
	CameraComponent = CreateDefaultSubobject<UGCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->Setup();
	InventoryComponent = CreateDefaultSubobject<UGInventoryComponent>(TEXT("InventoryComponent"));
	CharacterStatsComponent = CreateDefaultSubobject<UGCharacterStatsComponent>(TEXT("CharacterStatsComponent"));
	AbilityComponent = CreateDefaultSubobject<UGAbilityComponent>(TEXT("AbilityComponent"));
	DialogueComponent = CreateDefaultSubobject<UGDialogueComponent>(TEXT("DialogueComponent"));
	CharacterProgressionComponent = CreateDefaultSubobject<UGCharacterProgressionComponent>(TEXT("CharacterProgressionComponent"));
	CharacterInfoComponent = CreateDefaultSubobject<UGCharacterInfoComponent>(TEXT("CharacterInfoComponent"));

	// Disable the rotation of the character to face the camera
	bUseControllerRotationYaw = true;

	// Enable network replication
	SetReplicates(true);
	SetReplicateMovement(true);
}

// Called when the game starts or when spawned
void AGPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (CharacterInputComponent)
	{
		CharacterInputComponent->SetupInputComponent(PlayerInputComponent);
	}

}

