// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/NetMainMenuWidget.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Framework/MultiplayGameInstance.h" 
#include "Kismet/GameplayStatics.h"

void UNetMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Host 버튼에 클릭 이벤트 연결
	if (Button_Host)
	{
		Button_Host->OnClicked.AddDynamic(this, &UNetMainMenuWidget::OnHostClicked);
	}

	// Join 버튼에 클릭 이벤트 연결
	if (Button_Join)
	{
		Button_Join->OnClicked.AddDynamic(this, &UNetMainMenuWidget::OnJoinClicked);
	}
}

void UNetMainMenuWidget::OnHostClicked()
{
	UMultiplayGameInstance* GI = Cast<UMultiplayGameInstance>(GetGameInstance());
	if (GI)
	{
		// HostGame 호출 (맵 이름 전달)
		GI->HostGame(GameMapName);
	}
}

void UNetMainMenuWidget::OnJoinClicked()
{
	UMultiplayGameInstance* GI = Cast<UMultiplayGameInstance>(GetGameInstance());
	if (GI)
	{
		// 텍스트 박스에 적힌 IP 주소 가져오기
		FString IpAddress = TEXT("127.0.0.1"); // 기본값

		if (Edit_IP)
		{
			// 텍스트가 비어있지 않다면 가져옴
			FString InputText = Edit_IP->GetText().ToString();
			if (!InputText.IsEmpty())
			{
				IpAddress = InputText;
			}
		}

		// JoinGame 호출
		GI->JoinGame(IpAddress);
	}
}
