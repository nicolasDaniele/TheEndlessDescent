#include "Characters/TED_Character_Base.h"

ATED_Character_Base::ATED_Character_Base()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon Mesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ATED_Character_Base::BeginPlay()
{
	Super::BeginPlay();
}