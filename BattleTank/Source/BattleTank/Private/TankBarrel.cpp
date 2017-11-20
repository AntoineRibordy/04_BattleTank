// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"

void UTankBarrel::Elevate(float RelativeSpeed) 
{
	// Move the barrel the right amount this frame
	// given a max elevation speed, and the frame time
	UWorld* WorldRef = GetWorld();
	UStaticMeshComponent* StaticMeshRef = (UStaticMeshComponent*)this;
	USceneComponent* SceneComponentRef = (USceneComponent*)this;
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * WorldRef->DeltaTimeSeconds;
	auto RawNewElevation = StaticMeshRef->RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SceneComponentRef->SetRelativeRotation(FRotator(Elevation, 0, 0));
}

