// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/NetMainHUDWidget.h"
#include "Components/TextBlock.h"

void UNetMainHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 생성 시 결과 텍스트 숨기기
	if (ResultTEXT)
	{
		ResultTEXT->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UNetMainHUDWidget::UpdateHUD(int32 Time, int32 MyScore, int32 EnemyScore)
{
	if (TimeTEXT)
	{
		TimeTEXT->SetText(FText::AsNumber(Time));
	}
	if (MyScoreTEXT)
	{
		MyScoreTEXT->SetText(FText::AsNumber(MyScore));
	}
	if (EnemyScoreTEXT)
	{
		EnemyScoreTEXT->SetText(FText::AsNumber(EnemyScore));
	}
}

void UNetMainHUDWidget::ShowResult(const FString& ResultText, FLinearColor Color)
{
	if (ResultTEXT)
	{
		ResultTEXT->SetText(FText::FromString(ResultText));
		ResultTEXT->SetColorAndOpacity(FSlateColor(Color));
		ResultTEXT->SetVisibility(ESlateVisibility::Visible);
	}
}
