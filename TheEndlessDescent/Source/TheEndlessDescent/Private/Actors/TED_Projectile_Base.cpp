#include "Actors/TED_Projectile_Base.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
//#include "NiagaraFunctionLibrary.h"
#include "TED.h"

ATED_Projectile_Base::ATED_Projectile_Base()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	BoxCollider = CreateDefaultSubobject<UBoxComponent>("Box Collider");
	BoxCollider->SetupAttachment(Mesh);
	BoxCollider->SetCollisionObjectType(ECC_Projectile);
	BoxCollider->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	BoxCollider->SetCollisionResponseToAllChannels(ECR_Ignore);
	BoxCollider->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	BoxCollider->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Overlap);
	BoxCollider->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement");
	ProjectileMovement->InitialSpeed = 550.0f;
	ProjectileMovement->MaxSpeed = 550.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
}

void ATED_Projectile_Base::BeginPlay()
{
	Super::BeginPlay();

	SetLifeSpan(LifeSpan);
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &ATED_Projectile_Base::BoxOverlap);
}

void ATED_Projectile_Base::Destroyed()
{
	if (!bHit && !HasAuthority())
	{
		//UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), FRotator::ZeroRotator);
		//::SpawnSystemAtLocation(this, ImpactEffect, GetActorLocation());
	}

	Super::Destroyed();
}

void ATED_Projectile_Base::BoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), FRotator::ZeroRotator);
	//UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, ImpactEffect, GetActorLocation());

	if (HasAuthority())
	{
		if (UAbilitySystemComponent* TargetAbilitySystemComponent = 
			UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
		{
			TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*DamageSpecHandle.Data.Get());
		}

		//Destroy();
	}
	else
	{
		bHit = true;
	}
}