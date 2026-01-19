// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetGameState.h"
#include "Net/UnrealNetwork.h"
#include "Framework/NetPlayerController.h"
#include "Engine/World.h"

ANetGameState::ANetGameState()
{
	PrimaryActorTick.bCanEverTick = true;
	RemainingTime = 60.0f;
}

void ANetGameState::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		RemainingTime = MaxGameTime;
		bIsGameOver = false;
	}
}

void ANetGameState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 시간 감소 로직 (서버만 수행)
	if (HasAuthority() && !bIsGameOver)
	{
		if (RemainingTime > 0.0f)
		{
			RemainingTime -= DeltaTime;
		}
		else
		{
			// 시간 종료 -> 게임 오버 처리
			RemainingTime = 0.0f;
			bIsGameOver = true;
			Multicast_GameOver(ServerScore, ClientScore);
		}
	}
}

void ANetGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ANetGameState, RemainingTime);
	DOREPLIFETIME(ANetGameState, ServerScore);
	DOREPLIFETIME(ANetGameState, ClientScore);
}

void ANetGameState::AddScore(bool bIsServerPlayer)
{
	if (HasAuthority() && !bIsGameOver)
	{
		if (bIsServerPlayer) ServerScore++;
		else ClientScore++;
	}
}

void ANetGameState::Multicast_GameOver_Implementation(int32 FinalServerScore, int32 FinalClientScore)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; ++It)
	{
		ANetPlayerController* PC = Cast<ANetPlayerController>(It->Get());
		if (PC && PC->IsLocalController())
		{
			PC->OnMatchEnded(FinalServerScore, FinalClientScore);
		}
	}
}
