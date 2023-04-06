// Fill out your copyright notice in the Description page of Project Settings.


#include "GAI/GAIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionSystem.h"

AGAIController::AGAIController()
{
	
	AIConfigSight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AIConfigSight"));
	AIConfigSight->SightRadius = 1000.f;
	AIConfigSight->LoseSightRadius = 2000.f;
	AIConfigSight->PeripheralVisionAngleDegrees = 90.f;
	AIConfigSight->DetectionByAffiliation.bDetectEnemies = true;
	AIConfigSight->DetectionByAffiliation.bDetectFriendlies = true;
	AIConfigSight->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	AIPerceptionComponent->ConfigureSense(*AIConfigSight);
	AIPerceptionComponent->SetDominantSense(AIConfigSight->GetSenseImplementation());
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ThisClass::OnPerceptionUpdated);

	UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, AIConfigSight->GetSenseImplementation(), GetPawn());
}

//
void AGAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!InPawn) { return; }

	//AICharacter = Cast<ADreadLordAICharacter>(InPawn);

	/*if (AICharacter)
	{
		if (AICharacter->GetBehaviorTree())
		{
			BlackboardComponent->InitializeBlackboard(*(AICharacter->GetBehaviorTree()->BlackboardAsset));
		}

		AICharacter->SetAIController(this);
	}*/


	//RunBehaviorTree(AICharacter->GetBehaviorTree());
}

void AGAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGAIController::OnPerceptionUpdated(const TArray<AActor*>& PerceivedActors)
{
	for (auto& Actor : PerceivedActors)
	{
		//ADreadLordPlayerCharacter* Player = Cast<ADreadLordPlayerCharacter>(Actor);
		//if (Player)
		//{
		//	TArray<AActor*> OutActors;
		//	AIPerceptionComponent->GetCurrentlyPerceivedActors(SightSense, OutActors);
		//	if (OutActors.Contains(Player))
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("Player entered line of sight!"));
		//		//BlackboardComponent->SetValueAsObject("PlayerCharacter", Player);
		//	}
		//	else
		//	{
		//		UE_LOG(LogTemp, Warning, TEXT("Player exited line of sight!"));
		//		//BlackboardComponent->SetValueAsObject("PlayerCharacter", nullptr);
		//	}

		//}
	}
}