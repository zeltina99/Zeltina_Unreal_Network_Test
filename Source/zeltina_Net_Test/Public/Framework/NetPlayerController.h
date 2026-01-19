// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NetPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API ANetPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ANetPlayerController();

	// 게임 종료 시 GameState가 호출
	void OnMatchEnded(int32 ServerScore, int32 ClientScore);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UNetMainHUDWidget> MainWidgetClass;

	UPROPERTY()
	TObjectPtr<class UNetMainHUDWidget> MainWidgetInstance;

};
