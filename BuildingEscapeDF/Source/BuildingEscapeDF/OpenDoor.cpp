// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Gameframework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UOpenDoor::OpenDoor()
{
    AActor* Owner = GetOwner();
    FRotator newRotation = FRotator(0.0f, -60.0f, 0.0f);
    
    Owner->SetActorRotation(newRotation);
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
    actorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if(pressurePlate && pressurePlate->IsOverlappingActor(actorThatOpens))
    {
        OpenDoor();
    }
}

