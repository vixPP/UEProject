// Fill out your copyright notice in the Description page of Project Settings.
#include "CppBaseActor.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	//ShowInformation();	
	InitialLocation = GetActorLocation();
	SinMovement();
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation()
{
	UE_LOG(LogTemp, Display, TEXT("info"));
}


void ACppBaseActor::SinMovement()
{
	FVector CurrentLocation = InitialLocation;

	float Time = GetWorld()->GetTimeSeconds();
	float Offset = FMath::Sin(Time * Frequency) * Amplitude;

	CurrentLocation.Z += Offset;

	SetActorLocation(CurrentLocation);
}