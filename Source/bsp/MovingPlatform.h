// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class BSP_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	bool state = false;//closed door
	UPROPERTY(EditAnywhere, Category="Velocity")
	FVector Velocity = FVector(0, 0, 0);
	FVector CurrentLocation = FVector(0, 0, 0);
	FVector StartLocation = FVector(0, 0, 0); 
	float Time = 0;
	UPROPERTY(EditAnywhere)
	float Distance = 500;
	UPROPERTY(EditAnywhere)
	float Wait = 1;
	UPROPERTY(VisibleAnywhere)
	float DistanceMoved = -1;

};
