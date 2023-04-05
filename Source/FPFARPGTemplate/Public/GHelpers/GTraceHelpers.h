// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GTraceHelpers.generated.h"

/**
 * 
 */
UCLASS()
class FPFARPGTEMPLATE_API UGTraceHelpers : public UObject
{
	GENERATED_BODY()

public:
	// Function to perform a cone trace and return overlapped actors
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	static void PerformConeTrace(UWorld* World, AActor* IgnoredActor, const FVector& Start, const FVector& Direction, float Distance, float ConeHalfAngle, int32 NumRays, TArray<FHitResult>& OutHits);
};
