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
