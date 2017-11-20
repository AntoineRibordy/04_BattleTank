// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshSocket.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Move the barrel the right amount this frame
	// given a max rotation speed, and the frame time
	UWorld* WorldRef = GetWorld();
	UStaticMeshComponent* StaticMeshRef = (UStaticMeshComponent*)this;
	USceneComponent* SceneComponentRef = (USceneComponent*)this;
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * WorldRef->DeltaTimeSeconds;
	auto Rotation = StaticMeshRef->RelativeRotation.Yaw + RotationChange;
	SceneComponentRef->SetRelativeRotation(FRotator(0, Rotation, 0));
}




