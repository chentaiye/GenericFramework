// Copyright ChenTaiye 2025,. All Rights Reserved.

#include "ExternalData.h"

#include "BPFunctions_Json.h"
#include "BPFunctions/BPFunctions_Desktop.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "Misc/DataValidation.h"
#include "Misc/Paths.h"
#include "UObject/ObjectSaveContext.h"

#define LOCTEXT_NAMESPACE "FExternalDataModule"

DECLARE_LOG_CATEGORY_CLASS(LogExternalData, Log, All);

UExternalData::UExternalData()
{
}

void UExternalData::PostLoad()
{
	Super::PostLoad();

	if (HasAnyFlags(RF_ClassDefaultObject))
	{
		return;
	}

	this->LoadData();
}

#if WITH_EDITOR
void UExternalData::PostSaveRoot(FObjectPostSaveRootContext ObjectSaveContext)
{
	Super::PostSaveRoot(ObjectSaveContext);

	if (!SaveData())
	{
		UE_LOG(LogExternalData, Warning, TEXT("%s : Can not save data!"), ANSI_TO_TCHAR(__FUNCTION__))
	}
}
#endif

#if WITH_EDITOR
EDataValidationResult UExternalData::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = CombineDataValidationResults(Super::IsDataValid(Context), EDataValidationResult::Valid);

	if (!RowStruct.IsValid())
	{
		Result = EDataValidationResult::Invalid;
		Context.AddError(LOCTEXT("ExternalData_RowStructNull", "Row Struct can not empty."));
	}

	return Result;
}
#endif

FString UExternalData::GetJsonFilePath() const
{
	static FString ExternalData(TEXT("ExternalData"));
	static FString Extension(TEXT(".json"));

	return FPaths::Combine(FPaths::ProjectConfigDir(), ExternalData, GetName() + Extension);
}

const UScriptStruct* UExternalData::GetRowScriptStruct() const
{
	return RowStruct.GetScriptStruct();
}

bool UExternalData::LoadData()
{
	if (!RowStruct.IsValid())
	{
		return false;
	}

	bool bResult = UBPFunctions_Json::JsonFileToStruct(GetJsonFilePath(), RowStruct.GetScriptStruct(), RowStruct.GetMutableMemory());
	return bResult;
}

bool UExternalData::SaveData()
{
	if (!RowStruct.IsValid())
	{
		return false;
	}

	const FString JsonFilePath = GetJsonFilePath();
	UBPFunctions_Desktop::CreateDirectory(FPaths::GetPath(JsonFilePath));

	bool bResult = UBPFunctions_Json::StructToJsonFile(JsonFilePath, RowStruct.GetScriptStruct(), RowStruct.GetMemory());
	return bResult;
}

void UExternalData::Reload()
{
	LoadData();
}

#undef LOCTEXT_NAMESPACE

