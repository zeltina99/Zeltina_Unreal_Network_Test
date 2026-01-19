// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/NetSpawner.h"
#include "Item/NetPickupItem.h"
#include "NavigationSystem.h"

// Sets default values
ANetSpawner::ANetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ANetSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ANetSpawner::SpawnItem, SpawnInterval, true);
	}

}

void ANetSpawner::SpawnItem()
{
	if (!ItemClass) return;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavSystem)
	{
		FNavLocation RandomLocation;
		if (NavSystem->GetRandomPointInNavigableRadius(FVector::ZeroVector, 2000.0f, RandomLocation))
		{
			GetWorld()->SpawnActor<ANetPickupItem>(ItemClass, RandomLocation.Location + FVector(0, 0, 50), FRotator::ZeroRotator);
		}
	}
}


