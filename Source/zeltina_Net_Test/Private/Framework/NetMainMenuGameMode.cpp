// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetMainMenuGameMode.h"
#include "Framework/NetMainMenuPlayerController.h"

ANetMainMenuGameMode::ANetMainMenuGameMode()
{
	DefaultPawnClass = nullptr;

	PlayerControllerClass = ANetMainMenuPlayerController::StaticClass();
}