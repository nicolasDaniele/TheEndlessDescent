#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "TED_AssetManager.generated.h"

UCLASS()
class THEENDLESSDESCENT_API UTED_AssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	static UTED_AssetManager& Get();

protected:
	virtual void StartInitialLoading() override;
};
