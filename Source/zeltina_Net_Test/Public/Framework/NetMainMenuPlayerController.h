// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetMainMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API ANetMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	// 에디터에서 WBP_MainMenu를 넣어줄 변수
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> MenuWidgetClass = nullptr;

};
