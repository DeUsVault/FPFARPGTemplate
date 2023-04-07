// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GPickup.generated.h"

UCLASS()
class FPFARPGTEMPLATE_API AGPickup : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the pickup is collected
	virtual void OnPickedUp(class ACharacter* Character);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// The mesh of the pickup
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	class UStaticMeshComponent* Mesh;

	// The collision component for detecting overlaps
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Pickup")
	class USphereComponent* CollisionSphere;

private:
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
