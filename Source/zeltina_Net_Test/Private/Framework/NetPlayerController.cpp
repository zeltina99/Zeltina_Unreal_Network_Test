// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetPlayerController.h"
#include "UI/NetMainHUDWidget.h"
#include "Framework/NetGameState.h"

ANetPlayerController::ANetPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ANetPlayerController::BeginPlay()
{
	if (IsLocalController() && MainWidgetClass)
	{
		// CreateWidget의 반환값은 Raw Pointer지만, TObjectPtr에 대입하면 알아서 처리됨
		MainWidgetInstance = CreateWidget<UNetMainHUDWidget>(this, MainWidgetClass);
		if (MainWidgetInstance)
		{
			MainWidgetInstance->AddToViewport();
		}
	}
	bShowMouseCursor = false;

	FInputModeGameOnly GameInputMode;
	SetInputMode(GameInputMode);
}

void ANetPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MainWidgetInstance && IsLocalController())
	{
		ANetGameState* GS = GetWorld()->GetGameState<ANetGameState>();
		if (GS)
		{
			int32 MyScore = HasAuthority() ? GS->GetServerScore() : GS->GetClientScore();
			int32 EnemyScore = HasAuthority() ? GS->GetClientScore() : GS->GetServerScore();

			MainWidgetInstance->UpdateHUD(GS->GetRemainingTime(), MyScore, EnemyScore);
		}
	}
}

void ANetPlayerController::OnMatchEnded(int32 ServerScore, int32 ClientScore)
{
	if (!MainWidgetInstance) return;

	FString ResultStr;
	FLinearColor ResultColor;

	bool bAmIServer = HasAuthority();
	int32 MyScore = bAmIServer ? ServerScore : ClientScore;
	int32 EnemyScore = bAmIServer ? ClientScore : ServerScore;

	if (MyScore > EnemyScore)
	{
		ResultStr = TEXT("승리");
		ResultColor = FLinearColor::Green;
	}
	else if (MyScore < EnemyScore)
	{
		ResultStr = TEXT("패배");
		ResultColor = FLinearColor::Red;
	}
	else
	{
		ResultStr = TEXT("무승부");
		ResultColor = FLinearColor::Gray;
	}

	MainWidgetInstance->ShowResult(ResultStr, ResultColor);
}