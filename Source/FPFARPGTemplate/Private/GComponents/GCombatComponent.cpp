// Copyright(c) 2023 Full Power Fantasy LLCPermission is hereby granted, free of charge, to any person obtaining a copyof this software and associated documentation files(the "Software"), to dealin the Software without restriction, including without limitation the rightsto use, copy, modify, merge, publish, distribute, sublicense, and /or sellcopies of the Software, and to permit persons to whom the Software isfurnished to do so, subject to the following conditions :The above copyright notice and this permission notice shall be included in allcopies or substantial portions of the Software.THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS ORIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THEAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THESOFTWARE.


#include "GComponents/GCombatComponent.h"
#include "GItems/GWeapon.h"
#include "GComponents/GEventsComponent.h"
#include "Components/BoxComponent.h"

// Sets default values for this component's properties
UGCombatComponent::UGCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UGCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	// Bind the function to the delegate event
	UGEventsComponent* EventsComponent = Cast<UGEventsComponent>(GetOwner()->GetComponentByClass(UGEventsComponent::StaticClass()));
	if (EventsComponent)
	{
		EventsComponent->OnWeaponEquipped.AddDynamic(this, &ThisClass::OnWeaponEquipped);
	}
	// ...
	
}


// Called every frame
void UGCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UGCombatComponent::OnWeaponEquipped(AGWeapon* Weapon)
{
	// Store the reference to the equipped weapon
	EquippedWeapon = Weapon;
}


void UGCombatComponent::EnableWeaponCollision()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->GetCollisionBox()->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void UGCombatComponent::DisableWeaponCollision()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->GetCollisionBox()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}
