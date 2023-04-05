// Fill out your copyright notice in the Description page of Project Settings.


#include "GAbilities/GAbility.h"
#include "TimerManager.h"
#include "GameFramework/Character.h"

UGAbility::UGAbility()
{
	Cooldown = 0.f;
	bIsReady = true;
}

void UGAbility::Activate()
{
	// The actual functionality of the ability should be implemented in blueprints
}

void UGAbility::StartCooldown()
{
	if (bIsReady)
	{
		bIsReady = false;
		GetWorld()->GetTimerManager().SetTimerForNextTick(this, &UGAbility::CooldownTimerExpired);
	}
}

void UGAbility::CooldownTimerExpired()
{
	bIsReady = true;
}