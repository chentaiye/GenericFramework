// Copyright ChenTaiye 2025. All Rights Reserved.

#if WITH_DEV_AUTOMATION_TESTS

#include "Tests/ExternalDataSmokeTestTypes.h"

#include "HAL/FileManager.h"
#include "Misc/AutomationTest.h"
#include "Misc/Guid.h"
#include "Misc/Paths.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FExternalDataSaveLoadSmokeTest,
	"GenericCommunication.ExternalData.SaveLoad",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FExternalDataSaveLoadSmokeTest::RunTest(const FString& Parameters)
{
	const FString AssetName = FString::Printf(TEXT("ExternalDataSmoke_%s"), *FGuid::NewGuid().ToString(EGuidFormats::Digits));
	UExternalDataSmokeTestAsset* ExternalData = NewObject<UExternalDataSmokeTestAsset>(GetTransientPackage(), *AssetName);

	const FString ExpectedJsonPath = FPaths::Combine(FPaths::ProjectConfigDir(), TEXT("ExternalData"), AssetName + TEXT(".json"));
	TestEqual(TEXT("ExternalData resolves to Config/ExternalData"), ExternalData->GetJsonFilePath(), ExpectedJsonPath);

	const FExternalDataSmokeRow SavedRow = { 42, TEXT("Smoke") };
	ExternalData->SetRowValue(SavedRow);

	TestTrue(TEXT("ExternalData save succeeds"), ExternalData->SaveData());
	TestTrue(TEXT("ExternalData json file exists"), IFileManager::Get().FileExists(*ExpectedJsonPath));

	const FExternalDataSmokeRow ChangedRow = { -1, TEXT("Changed") };
	ExternalData->SetRowValue(ChangedRow);

	TestTrue(TEXT("ExternalData load succeeds"), ExternalData->LoadData());

	const FExternalDataSmokeRow& LoadedRow = ExternalData->GetRowValue();
	TestEqual(TEXT("Loaded number matches saved value"), LoadedRow.Number, SavedRow.Number);
	TestEqual(TEXT("Loaded label matches saved value"), LoadedRow.Label, SavedRow.Label);

	IFileManager::Get().Delete(*ExpectedJsonPath, false, true, true);
	return true;
}

#endif
