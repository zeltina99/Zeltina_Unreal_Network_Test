// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NetMainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ZELTINA_NET_TEST_API UNetMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnHostClicked();

	UFUNCTION()
	void OnJoinClicked();

protected:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Host;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UButton> Button_Join;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UEditableTextBox> Edit_IP;

	FString GameMapName = TEXT("/Game/Map/TestMap");

};
