// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/TED_CahracterBase.h"

// Sets default values
ATED_CahracterBase::ATED_CahracterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATED_CahracterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATED_CahracterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATED_CahracterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

