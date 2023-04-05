// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GCameraComponent.generated.h"


// CameraComponent handles all camera-related functionality
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGCameraComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGCameraComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Set up the camera component and its related properties
	void Setup();

	// Get the forward vector of the camera
	FVector GetForwardVector();

	// Get the right vector of the camera
	FVector GetRightVector();

	// The length of the Spring Arm attached to the camera
	UPROPERTY(EditAnywhere, Category = "Camera")
	float SpringArmLength;

	// The pitch angle of the camera
	UPROPERTY(EditAnywhere, Category = "Camera")
	float CameraPitch;

	// Reference to the Spring Arm component
	UPROPERTY()
	class USpringArmComponent* SpringArmComponent;

	// Reference to the Camera component
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	class UCameraComponent* Camera;
};
