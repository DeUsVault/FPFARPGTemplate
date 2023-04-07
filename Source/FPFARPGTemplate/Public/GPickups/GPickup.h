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
