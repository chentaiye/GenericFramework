// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "K2Node_AsyncAction.h"
#include "K2Node_ListenForGameplayMessages.generated.h"

class FBlueprintActionDatabaseRegistrar;
class FKismetCompilerContext;
class FMulticastDelegateProperty;
class FString;
class UEdGraph;
class UEdGraphPin;
class UObject;

/** 在蓝图中提供专用的 GameplayMessage 监听节点，并根据选定载荷结构体调整回调输出。 */
UCLASS(MinimalAPI)
class UK2Node_ListenForGameplayMessages : public UK2Node_AsyncAction
{
	GENERATED_BODY()

	//~UEdGraphNode interface
	virtual void PostReconstructNode() override;
	virtual void PinDefaultValueChanged(UEdGraphPin* ChangedPin) override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
	virtual FString GetPinMetaData(FName InPinName, FName InKey) override;
	//~End of UEdGraphNode interface

	//~UK2Node interface
	virtual void GetMenuActions(FBlueprintActionDatabaseRegistrar& ActionRegistrar) const override;
	virtual void AllocateDefaultPins() override;
	//~End of UK2Node interface

protected:
	virtual bool HandleDelegates(
		const TArray<FBaseAsyncTaskHelper::FOutputPinAndLocalVariable>& VariableOutputs, UEdGraphPin* ProxyObjectPin,
		UEdGraphPin*& InOutLastThenPin, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext) override;

private:
	/** 在异步回调展开时补上 GetPayload 调用，把代理对象中缓存的原始消息复制到蓝图输出。 */
	bool HandlePayloadImplementation(
		FMulticastDelegateProperty* CurrentProperty,
		const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& ProxyObjectVar,
		const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& PayloadVar,
		const FBaseAsyncTaskHelper::FOutputPinAndLocalVariable& ActualChannelVar,
		UEdGraphPin*& InOutLastActivatedThenPin, UEdGraph* SourceGraph, FKismetCompilerContext& CompilerContext);

	/** 让 Payload 输出 pin 跟随 PayloadType 选择的结构体，保证蓝图连线拿到强类型载荷。 */
	bool RefreshOutputPayloadType();

	/** 获取监听回调暴露给蓝图的消息载荷输出 pin。 */
	UEdGraphPin* GetPayloadPin() const;

	/** 获取用于选择监听载荷结构体的输入 pin。 */
	UEdGraphPin* GetPayloadTypePin() const;

	/** 获取实际触发消息的频道输出 pin，PartialMatch 时它可能是注册频道的子频道。 */
	UEdGraphPin* GetOutputChannelPin() const;
};
