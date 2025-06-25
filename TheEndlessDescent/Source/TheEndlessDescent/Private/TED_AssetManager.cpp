#include "TED_AssetManager.h"
#include "TED_GameplayTags.h"
#include "AbilitySystemGlobals.h"

UTED_AssetManager& UTED_AssetManager::Get()
{
	check(GEngine);

	UTED_AssetManager* TedAssetManaget = Cast<UTED_AssetManager>(GEngine->AssetManager);
	return *TedAssetManaget;
}

void UTED_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FTED_GameplayTags::InitializeNativeGameplayTags();

	// Required to use TargetData
	UAbilitySystemGlobals::Get().InitGlobalData();
}