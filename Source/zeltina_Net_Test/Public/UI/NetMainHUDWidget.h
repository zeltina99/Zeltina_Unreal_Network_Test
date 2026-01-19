// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NetMainHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API UNetMainHUDWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	void UpdateHUD(int32 Time, int32 MyScore, int32 EnemyScore);
	void ShowResult(const FString& ResultText, FLinearColor Color);

public:
	// 텍스트 블록 포인터에 TObjectPtr 적용
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> TimeTEXT;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> MyScoreTEXT;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> EnemyScoreTEXT;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UTextBlock> ResultTEXT;

};
