// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/NetGameMode.h"
#include "Framework/NetGameState.h"
#include "Framework/NetPlayerController.h"

ANetGameMode::ANetGameMode()
{
	GameStateClass = ANetGameState::StaticClass();
	PlayerControllerClass = ANetPlayerController::StaticClass();
}
