// Fill out your copyright notice in the Description page of Project Settings.


#include "Item/NetPickupItem.h"

// Sets default values
ANetPickupItem::ANetPickupItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANetPickupItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANetPickupItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

