// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MultiplayGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API UMultiplayGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// 호스트(서버)로 방 만들기
	UFUNCTION(BlueprintCallable, Category = "Network")
	void HostGame(FString LevelName);

	// IP 주소를 입력받아 접속하기
	UFUNCTION(BlueprintCallable, Category = "Network")
	void JoinGame(FString IPAddress);

};
