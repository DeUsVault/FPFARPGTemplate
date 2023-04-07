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


#include "GUI/GHUD.h"
#include "GComponents/GEventsComponent.h"

#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Components/TextBlock.h"


void UGHUD::NativeConstruct()
{
	Super::NativeConstruct();

	// Get the player controller
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		// Get the controlled pawn and cast it to your specific player character class
		APawn* Pawn = PlayerController->GetPawn();

		if (Pawn)
		{
			// Get the GEventsComponent from the player character
			UGEventsComponent* EventsComponent = Pawn->FindComponentByClass<UGEventsComponent>();

			if (EventsComponent)
			{
				// Bind the OnHealthChanged delegate to the UpdateHealthDisplay function
				EventsComponent->OnHealthChanged.AddDynamic(this, &ThisClass::UpdateHealthDisplay);
			}
		}
	}
}


void UGHUD::UpdateHealthDisplay(float NewHealth)
{
	// Retrieve the Health TextBlock from the UMG Widget Blueprint
	UTextBlock* HealthTextBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("HealthTextBlock")));

	if (HealthTextBlock)
	{
		// Convert the new health value to a string with a desired format (e.g., no decimal points)
		FText NewHealthText = FText::AsNumber(FMath::RoundToInt(NewHealth));

		// Update the TextBlock with the new health value
		HealthTextBlock->SetText(NewHealthText);
	}
}

