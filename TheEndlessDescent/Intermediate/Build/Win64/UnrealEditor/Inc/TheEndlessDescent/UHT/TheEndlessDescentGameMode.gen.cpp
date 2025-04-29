// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TheEndlessDescent/TheEndlessDescentGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTheEndlessDescentGameMode() {}

// Begin Cross Module References
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
THEENDLESSDESCENT_API UClass* Z_Construct_UClass_ATheEndlessDescentGameMode();
THEENDLESSDESCENT_API UClass* Z_Construct_UClass_ATheEndlessDescentGameMode_NoRegister();
UPackage* Z_Construct_UPackage__Script_TheEndlessDescent();
// End Cross Module References

// Begin Class ATheEndlessDescentGameMode
void ATheEndlessDescentGameMode::StaticRegisterNativesATheEndlessDescentGameMode()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATheEndlessDescentGameMode);
UClass* Z_Construct_UClass_ATheEndlessDescentGameMode_NoRegister()
{
	return ATheEndlessDescentGameMode::StaticClass();
}
struct Z_Construct_UClass_ATheEndlessDescentGameMode_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TheEndlessDescentGameMode.h" },
		{ "ModuleRelativePath", "TheEndlessDescentGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATheEndlessDescentGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AGameModeBase,
	(UObject* (*)())Z_Construct_UPackage__Script_TheEndlessDescent,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::ClassParams = {
	&ATheEndlessDescentGameMode::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008802ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ATheEndlessDescentGameMode()
{
	if (!Z_Registration_Info_UClass_ATheEndlessDescentGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATheEndlessDescentGameMode.OuterSingleton, Z_Construct_UClass_ATheEndlessDescentGameMode_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ATheEndlessDescentGameMode.OuterSingleton;
}
template<> THEENDLESSDESCENT_API UClass* StaticClass<ATheEndlessDescentGameMode>()
{
	return ATheEndlessDescentGameMode::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(ATheEndlessDescentGameMode);
ATheEndlessDescentGameMode::~ATheEndlessDescentGameMode() {}
// End Class ATheEndlessDescentGameMode

// Begin Registration
struct Z_CompiledInDeferFile_FID_Projects_Unrean_TheEndlessDescent_TheEndlessDescent_Source_TheEndlessDescent_TheEndlessDescentGameMode_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ATheEndlessDescentGameMode, ATheEndlessDescentGameMode::StaticClass, TEXT("ATheEndlessDescentGameMode"), &Z_Registration_Info_UClass_ATheEndlessDescentGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATheEndlessDescentGameMode), 3057364847U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Projects_Unrean_TheEndlessDescent_TheEndlessDescent_Source_TheEndlessDescent_TheEndlessDescentGameMode_h_1215250620(TEXT("/Script/TheEndlessDescent"),
	Z_CompiledInDeferFile_FID_Projects_Unrean_TheEndlessDescent_TheEndlessDescent_Source_TheEndlessDescent_TheEndlessDescentGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Projects_Unrean_TheEndlessDescent_TheEndlessDescent_Source_TheEndlessDescent_TheEndlessDescentGameMode_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
