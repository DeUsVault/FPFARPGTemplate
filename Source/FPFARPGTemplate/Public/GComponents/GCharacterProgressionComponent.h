// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GCharacterProgressionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGCharacterProgressionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGCharacterProgressionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Current level of the character
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression")
	int32 CurrentLevel;

	// Maximum level the character can reach
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression")
	int32 MaxLevel;

	// Current experience points of the character
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression")
	float CurrentXP;

	// Experience points required to reach the next level
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression")
	float XPToNextLevel;

	// Unspent ability points available for the character
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression")
	int32 AbilityPoints;

public:
	// Add experience points to the character
	UFUNCTION(BlueprintCallable, Category = "Progression")
	void AddXP(float XP);

	// Level up the character
	UFUNCTION(BlueprintCallable, Category = "Progression")
	void LevelUp();

	// Spend an ability point
	UFUNCTION(BlueprintCallable, Category = "Progression")
	void SpendAbilityPoint();

	// Get the current level of the character
	UFUNCTION(BlueprintPure, Category = "Progression")
	FORCEINLINE int32 GetCurrentLevel() const { return CurrentLevel; }

	// Get the current experience points of the character
	UFUNCTION(BlueprintPure, Category = "Progression")
	FORCEINLINE float GetCurrentXP() const { return CurrentXP; }

	// Get the unspent ability points of the character
	UFUNCTION(BlueprintPure, Category = "Progression")
	FORCEINLINE int32 GetAbilityPoints() const { return AbilityPoints; }

private:
	// Calculate the experience points required for the next level
	void CalculateXPToNextLevel();
};
