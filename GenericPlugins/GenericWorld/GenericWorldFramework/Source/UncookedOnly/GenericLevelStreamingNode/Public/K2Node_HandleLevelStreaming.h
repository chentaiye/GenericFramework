// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "K2Node.h"
#include "K2Node_AddPinInterface.h"
#include "K2Node_HandleLevelStreaming.generated.h"

class FBlueprintActionDatabaseRegistrar;
class FKismetCompilerContext;
class UEdGraph;
class UEdGraphPin;
class UGraphNodeContextMenuContext;
class UToolMenu;

UENUM()
enum class ELevelStreamingK2NodeOperation : uint8
{
	Load,
	Unload,
	SetVisibility
};

/** 把关卡流送 Handle 的批量执行、单项完成和整批完成整合成一个可增删关卡输入的蓝图节点。 */
UCLASS(MinimalAPI)
class UK2Node_HandleLevelStreaming : public UK2Node, public IK2Node_AddPinInterface
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FText GetTooltipText() const override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual FText GetMenuCategory() const override;
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;
	virtual void ExpandNode(FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;

public:
	virtual void AddInputPin() override;
	virtual bool CanAddPin() const override;
	virtual void RemoveInputPin(UEdGraphPin* Pin) override;
	virtual bool CanRemovePin(const UEdGraphPin* Pin) const override;

private:
	static FName MakeLevelPinName(int32 PinIndex);
	static bool IsLevelPinName(FName PinName);
	static bool TryGetLevelPinIndex(FName PinName, int32& OutIndex);

	UEdGraphPin* CreateLevelPin(int32 PinIndex);
	UEdGraphPin* GetThenPin() const;
	UEdGraphPin* GetOnceFinishPin() const;
	UEdGraphPin* GetFinishPin() const;
	UEdGraphPin* GetCompletedLevelPin() const;
	TArray<UEdGraphPin*> GetLevelPins() const;

	void CreateOperationPins();
	void InsertInputPinBefore(UEdGraphPin* Pin);
	bool CanInsertInputPinBefore(const UEdGraphPin* Pin) const;
	void RenameLevelPinsByCurrentOrder();

	FName GetOperationFunctionName() const;
	FText GetOperationNodeTitle() const;
	FText GetOperationTooltip() const;

private:
	UPROPERTY()
	ELevelStreamingK2NodeOperation Operation = ELevelStreamingK2NodeOperation::Load;

	UPROPERTY()
	int32 NumLevelPins = 1;
};
