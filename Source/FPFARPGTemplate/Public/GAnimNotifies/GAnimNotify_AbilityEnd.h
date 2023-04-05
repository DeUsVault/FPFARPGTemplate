// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GAnimNotify_AbilityEnd.generated.h"

/**
 * UGAnimNotify_EndAbility is a custom animation notify that is designed
 * to signal the end of an ability animation. It can be used in abilities
 * that need to know when the animation has completed.
 */
UCLASS()
class FPFARPGTEMPLATE_API UGAnimNotify_AbilityEnd : public UAnimNotify
{
	GENERATED_BODY()

public:
	// Function called when the animation notify is triggered
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};


