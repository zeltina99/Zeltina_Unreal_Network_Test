// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetMainMenuGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

ANetMainMenuGameMode::ANetMainMenuGameMode()
{
	DefaultPawnClass = nullptr;
}

void ANetMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();

	// 1. 위젯 생성 및 화면 부착
	if (MenuWidgetClass)
	{
		UUserWidget* MenuWidget = CreateWidget<UUserWidget>(GetWorld(), MenuWidgetClass);
		if (MenuWidget)
		{
			MenuWidget->AddToViewport();
		}
	}

	// 2. 마우스 커서 보이기 & 입력 모드 설정
	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	if (PC)
	{
		// 마우스 커서 켜기
		PC->bShowMouseCursor = true;

		// 입력 모드를 "UI 전용"으로 설정 (게임 캐릭터 조작 방지 및 UI 포커스)
		FInputModeUIOnly InputModeData;

		if (MenuWidgetClass)
		{
			InputModeData.SetWidgetToFocus(nullptr);
		}

		PC->SetInputMode(InputModeData);
	}
}
