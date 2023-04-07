// Fill out your copyright notice in the Description page of Project Settings.

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
