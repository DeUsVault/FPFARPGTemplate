// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GAbilityComponent.generated.h"


// Declare the dynamic multicast delegate
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndAbilityNotify);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGAbilityComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Activates the ability at the specified index
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ActivateAbilityBySlot(int32 Index);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void LoadAbilities();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<class UGAbility>> AbilityClasses;

	// Array of abilities
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Abilities")
	TArray<UGAbility*> Abilities;

	UPROPERTY(BlueprintAssignable, Category = "Abilities")
	FOnEndAbilityNotify OnEndAbilityNotify;
};
