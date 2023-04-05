// Fill out your copyright notice in the Description page of Project Settings.


#include "GHelpers/GTraceHelpers.h"
#include "Engine/World.h"


void UGTraceHelpers::PerformConeTrace(UWorld* World, AActor* IgnoredActor, const FVector& Start, const FVector& Direction, float Distance, float ConeHalfAngle, int32 NumRays, TArray<FHitResult>& OutHits)
{
	// Generate random points on the surface of the cone
	for (int32 i = 0; i < NumRays; ++i)
	{
		float Angle = FMath::RandRange(0.0f, ConeHalfAngle);
		float Azimuth = FMath::RandRange(0.0f, 360.0f);
		FVector RayDirection = Direction.RotateAngleAxis(Angle, FVector::UpVector);
		RayDirection = RayDirection.RotateAngleAxis(Azimuth, Direction);

		FHitResult HitResult;
		FVector End = Start + (RayDirection * Distance);
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(IgnoredActor);

		if (World && World->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, QueryParams))
		{
			OutHits.Add(HitResult);
		}
	}
}
