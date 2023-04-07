// Copyright (c) 2023 Full Power Fantasy LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

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
