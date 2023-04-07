// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FPFARPGTEMPLATE_API AGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:

		AGPlayerController();

		virtual void BeginPlay() override;

	private:
		UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<class UUserWidget> PlayerHUDClass;

		UPROPERTY()
		class UUserWidget* PlayerHUD;
};
