#include "Characters/TED_CahracterBase.h"

ATED_CahracterBase::ATED_CahracterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATED_CahracterBase::BeginPlay()
{
	Super::BeginPlay();
}