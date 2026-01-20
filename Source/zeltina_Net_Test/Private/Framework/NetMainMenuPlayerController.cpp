// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetMainMenuPlayerController.h"
#include "Blueprint/UserWidget.h"

void ANetMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 로컬 플레이어(내 화면)인 경우에만 UI 생성
	if (IsLocalController() && MenuWidgetClass)
	{
		UUserWidget* MenuWidget = CreateWidget<UUserWidget>(this, MenuWidgetClass);
		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
		}

		// 마우스 커서 설정
		bShowMouseCursor = true;
		FInputModeUIOnly InputModeData;
		SetInputMode(InputModeData);
	}
}
