// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"
// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	
	Super::Tick(DeltaTime);

	CurrentLocation = GetActorLocation();
	DistanceMoved = FVector::Distance(StartLocation, CurrentLocation);
	if (DistanceMoved < Distance)
	{
		CurrentLocation = CurrentLocation + Velocity * DeltaTime;
		SetActorLocation(CurrentLocation);
	}
	else
	{	
		FVector Dir = Velocity.GetSafeNormal();
		StartLocation = StartLocation + Dir * Distance;
		SetActorLocation(StartLocation);
		Velocity = -Velocity;	
	}
}

