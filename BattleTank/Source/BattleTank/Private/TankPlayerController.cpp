// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto PossessedTank = GetControlledTank();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	if (PossessedTank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player possessed Tank %s"), *PossessedTank->GetName());
	}

	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;


	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at this point
	}

	
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
	
}

// Get world location of linetrace through crosshair and returns true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	// Use dot to raycast through landscape
	// If we hit something, return true and coordinates of the hit
	// If we hit nothing, return false and return (0,0,0) as coordinates
	return true;
}


