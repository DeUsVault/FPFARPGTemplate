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
#include "Animation/AnimInstance.h"
#include "GCharacterAnimInstance.generated.h"

/**
 * UGCharacterAnimInstance class is responsible for handling animation-related tasks for the character.
 * It calculates the character's speed, direction, and falling state and updates the animation accordingly.
 */
UCLASS()
class FPFARPGTEMPLATE_API UGCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	// Initializes the animation instance and sets up any required properties.
	virtual void NativeInitializeAnimation() override;

	// Updates the animation instance with the character's current state.
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// The character's current speed.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Strafing")
	float Speed;

	// The direction of the character relative to its current rotation.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Strafing")
	float Direction;

	// Indicates if the character is currently in the air (falling or jumping).
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Strafing")
	bool bIsInAir;
};