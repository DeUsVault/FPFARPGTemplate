// Fill out your copyright notice in the Description page of Project Settings.


#include "GComponents/GCameraComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
UGCameraComponent::UGCameraComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SpringArmLength = 1000.0f;
	CameraPitch = -60.0f;

	// Create and configure the Spring Arm component
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComponent->bUsePawnControlRotation = false;
	SpringArmComponent->bInheritPitch = false;
	SpringArmComponent->bInheritYaw = false;
	SpringArmComponent->bInheritRoll = false;
	SpringArmComponent->bDoCollisionTest = false;


	// Create and configure the Camera component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
}


// Called when the game starts
void UGCameraComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGCameraComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// Set up the camera component and its related properties
void UGCameraComponent::Setup()
{
	// Attach the Spring Arm to the owner's root component
	SpringArmComponent->SetupAttachment(GetOwner()->GetRootComponent());
	// Set the target arm length and the relative rotation of the Spring Arm
	SpringArmComponent->TargetArmLength = SpringArmLength;
	SpringArmComponent->SetRelativeRotation(FRotator(CameraPitch, 0.0f, 0.0f));

	// Attach the Camera component to the Spring Arm component
	Camera->SetupAttachment(SpringArmComponent);
}


// Get the forward vector of the camera
FVector UGCameraComponent::GetForwardVector()
{
	return Camera ? Camera->GetForwardVector() : FVector();
}


// Get the right vector of the camera
FVector UGCameraComponent::GetRightVector()
{
	return Camera ? Camera->GetRightVector() : FVector();
}
