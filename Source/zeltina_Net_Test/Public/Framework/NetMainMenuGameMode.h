// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NetMainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API ANetMainMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ANetMainMenuGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MenuWidgetClass = nullptr;

};
