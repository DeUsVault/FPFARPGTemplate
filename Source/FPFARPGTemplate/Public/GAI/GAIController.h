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
#include "AIController.h"
#include "GAIController.generated.h"

/**
 * 
 */
UCLASS()
class FPFARPGTEMPLATE_API AGAIController : public AAIController
{
	GENERATED_BODY()

	public:

		//
		AGAIController();

		/** Configure Blackboard & BehaviorTree */
		virtual void OnPossess(APawn* InPawn) override;

		// Called every frame
		virtual void Tick(float DeltaTime) override;

		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTree* BehaviorTree;

		/** Variables for BehaviorTree */
		UPROPERTY(BlueprintReadWrite, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UBlackboardComponent* BlackboardComponent;

		/** Controls AICharacter's Pawn */
		UPROPERTY(BlueprintReadWrite, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UBehaviorTreeComponent* BehaviorTreeComponent;

		/** Processes perception stimulus */
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UAIPerceptionComponent* AIPerceptionComponent;

		/** Config info for AI Sight Perception */
		UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UAISenseConfig_Sight* AIConfigSight;

		/** Needed for function to get perceived actors */
		UPROPERTY(EditDefaultsOnly, Category = "Config")
		TSubclassOf<class UAISense> SightSense;

		/** Updated whenever an actor enters or leaves line of sight */
		UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*>& PerceivedActors);

		void AStarSearch(const class FFGWorldState& InitialWorldState, const  class FFGWorldState& GoalWorldState, const TArray< class UFGAction*>& AvailableActions, class TNodeMap& VisitedNodes);
	
};
