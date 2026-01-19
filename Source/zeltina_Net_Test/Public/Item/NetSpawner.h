// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NetSpawner.generated.h"

UCLASS()
class ZELTINA_NET_TEST_API ANetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANetSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<class ANetPickupItem> ItemClass;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	float SpawnInterval = 3.0f;

	FTimerHandle SpawnTimerHandle;

protected:
	UFUNCTION()
	void SpawnItem();
};
