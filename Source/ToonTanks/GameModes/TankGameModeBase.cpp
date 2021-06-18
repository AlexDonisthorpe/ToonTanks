// @AlexDonisthorpe 2021

#include "TankGameModeBase.h"

#include "Kismet/GameplayStatics.h"

void ATankGameModeBase::BeginPlay()
{
	// Get win/lose conditions
	HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	// Check type of actor killed
		// if enemy, points ++
		// if player, game over
}

void ATankGameModeBase::HandleGameStart()
{
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
}




