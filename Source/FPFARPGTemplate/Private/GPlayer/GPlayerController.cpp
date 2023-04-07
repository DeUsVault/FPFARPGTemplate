// Fill out your copyright notice in the Description page of Project Settings.


#include "GPlayer/GPlayerController.h"
#include "Blueprint/UserWidget.h"

 
AGPlayerController::AGPlayerController()
{
	bShowMouseCursor = true;
}

void AGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (PlayerHUDClass)
	{
		PlayerHUD = CreateWidget<UUserWidget>(this, PlayerHUDClass);
		if (PlayerHUD)
		{
			PlayerHUD->AddToViewport();
		}
	}
}