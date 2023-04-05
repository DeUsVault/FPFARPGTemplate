// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GPlayerCharacter.generated.h"

UCLASS()
class FPFARPGTEMPLATE_API AGPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// CharacterInputComponent handles all input-related functionality such as movement and attacks
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterInputComponent* CharacterInputComponent;

	// Custom camera component for top-down view
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
	class UGCameraComponent* CameraComponent;

	// InventoryComponent handles the player's inventory, gold, and item management
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGInventoryComponent* InventoryComponent;

	// CharacterStatsComponent handles character stats, health, leveling, and skill points
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterStatsComponent* CharacterStatsComponent;

	// AbilityComponent manages the player's abilities and their respective cooldowns
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGAbilityComponent* AbilityComponent;

	// PickupComponent handles interactions with pickups, such as collecting items and gold
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGPickupComponent* PickupComponent;

	// DialogueComponent handles dialogue interactions with NPCs and quest-related functionality
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGDialogueComponent* DialogueComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
	class UGCharacterProgressionComponent* CharacterProgressionComponent;
};
