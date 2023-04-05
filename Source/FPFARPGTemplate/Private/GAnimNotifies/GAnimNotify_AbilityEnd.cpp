// Fill out your copyright notice in the Description page of Project Settings.


#include "GAnimNotifies/GAnimNotify_AbilityEnd.h"
#include "GComponents/GAbilityComponent.h"
#include "GameFramework/Character.h"

/**
 * Notify is called when the animation notify is triggered in the animation sequence.
 * It finds the owning character and broadcasts the OnEndAbilityNotify delegate from
 * the character's ability component.
 *
 * @param MeshComp - The skeletal mesh component the notify is being triggered on
 * @param Animation - The animation sequence containing the notify
 */
void UGAnimNotify_AbilityEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	// Get the owning character
	ACharacter* OwningCharacter = Cast<ACharacter>(MeshComp->GetOwner());
	if (!OwningCharacter)
	{
		return;
	}

	// Get the ability component and call the delegate
	UGAbilityComponent* AbilityComponent = OwningCharacter->FindComponentByClass<UGAbilityComponent>();
	if (AbilityComponent)
	{
		AbilityComponent->OnEndAbilityNotify.Broadcast();
	}
}
