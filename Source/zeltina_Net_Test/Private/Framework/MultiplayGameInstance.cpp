// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/MultiplayGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UMultiplayGameInstance::HostGame(FString LevelName)
{
	UGameplayStatics::OpenLevel(this, FName(*LevelName), true, TEXT("listen"));

	UE_LOG(LogTemp, Warning, TEXT("Hosting Game at Level: %s"), *LevelName);
}

void UMultiplayGameInstance::JoinGame(FString IPAddress)
{
	if (IPAddress.IsEmpty())
	{
		IPAddress = TEXT("127.0.0.1");
	}

	UGameplayStatics::OpenLevel(this, FName(*IPAddress));

	UE_LOG(LogTemp, Warning, TEXT("Joining Game at IP: %s"), *IPAddress);
}
