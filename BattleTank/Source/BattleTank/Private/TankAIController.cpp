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