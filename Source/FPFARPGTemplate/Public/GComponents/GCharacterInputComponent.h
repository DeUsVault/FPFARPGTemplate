// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GCharacterInputComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGCharacterInputComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGCharacterInputComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Bind input actions and axis
	void SetupInputComponent(class UInputComponent* InputComponent);

	// Movement functions
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);

	// Turn functions
	void Turn(float AxisValue);
	void LookUp(float AxisValue);

	// Attack functions
	void ActivateAbilitySlot1();
	void ActivateAbilitySlot2();
	void ActivateAbilitySlot3();
	void ActivateAbilitySlot4();

	// Jump function
	void Jump();

	// Owner character
	class ACharacter* Character;
};
