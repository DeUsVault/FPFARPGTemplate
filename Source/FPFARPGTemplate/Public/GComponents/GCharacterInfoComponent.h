// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GDataTypes/GDataTypes.h"
#include "GCharacterInfoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FPFARPGTEMPLATE_API UGCharacterInfoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGCharacterInfoComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Info")
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Info")
	int32 Age;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Info")
	FString Race;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Info")
	EFaction Faction;

	// Checks if this character is hostile to the other character
	UFUNCTION(BlueprintCallable, Category = "Character Info")
	bool IsHostileTo(const UGCharacterInfoComponent* OtherCharacterInfo) const;

};
