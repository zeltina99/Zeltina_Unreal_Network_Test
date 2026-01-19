// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "NetGameState.generated.h"

/**
 * 
 */

// 승자 판별용 Enum
UENUM(BlueprintType)
enum class EMatchResult : uint8
{
	Playing,
	Victory,
	Defeat,
	Draw
};

UCLASS()
class ZELTINA_NET_TEST_API ANetGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ANetGameState();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	// 점수 추가 함수 (서버만 호출)
	void AddScore(bool bIsServerPlayer);

	// Getter
	UFUNCTION(BlueprintCallable, Category = "GameData")
	int32 GetServerScore() const { return ServerScore; }

	UFUNCTION(BlueprintCallable, Category = "GameData")
	int32 GetClientScore() const { return ClientScore; }

	UFUNCTION(BlueprintCallable, Category = "GameData")
	int32 GetRemainingTime() const { return FMath::CeilToInt(RemainingTime); }

public:
	// 게임 종료 시 결과를 클라이언트들에게 알리는 멀티캐스트
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_GameOver(int32 FinalServerScore, int32 FinalClientScore);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "GameRule")
	float MaxGameTime = 60.0f;

	UPROPERTY(Replicated)
	float RemainingTime = 0.0f;

	UPROPERTY(Replicated)
	int32 ServerScore = 0;

	UPROPERTY(Replicated)
	int32 ClientScore = 0;

	bool bIsGameOver = false;

};
