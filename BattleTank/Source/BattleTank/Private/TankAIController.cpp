// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//auto PossessedTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();
	
	if (PlayerTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player tank %s"), *PlayerTank->GetName());
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No player tank found"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		// TODO move towards the player
		
		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}	
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn)
		return Cast<ATank>(PlayerPawn);
	else return nullptr;
}