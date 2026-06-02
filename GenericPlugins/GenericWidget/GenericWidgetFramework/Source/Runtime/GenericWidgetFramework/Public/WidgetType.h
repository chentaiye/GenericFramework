// Copyright ChenTaiye 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"
/** #include "WidgetType.generated.h" */

class UGameplayTagSlot;

GENERICWIDGETFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(GenericLogUI, Log, All);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnActionWidgetRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnActionWidgetUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnLayoutRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnLayoutUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnRouteRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnRouteUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnLayerRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnLayerUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnSlotRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnSlotUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWidgetRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegister);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWidgetRegisterToOwner);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayMessage_Channel_UI_OnWidgetUnRegisterFromOwner);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Layer);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Layer_HUD);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Layer_Menu);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Layer_Modal);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Slot);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action_Back);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action_Confirm);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action_LeftShoulder);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action_RightShoulder);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Action_Menu);

UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Route);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Route_Layout);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Route_Layer);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Route_Slot);
UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_GameplayUI_Route_Widget);

template <typename T>
/** 保存通用 UI流程中的ExtractFromT对象Ptr数据，供运行时传递和蓝图访问。 */
struct ExtractFromTObjectPtr
{
	using Type = void;
};

/** 封装Extract From T对象指针。 */
template <typename T>
struct ExtractFromTObjectPtr<TObjectPtr<T>>
{
	using Type = T;
};

template <typename T>
/** 保存通用 UI流程中的ExtractFromRawPtr数据，供运行时传递和蓝图访问。 */
struct ExtractFromRawPtr
{
	using Type = void;
};

template <typename T>
/** 保存通用 UI流程中的ExtractFromRawPtr数据，供运行时传递和蓝图访问。 */
struct ExtractFromRawPtr<T*>
{
	using Type = T;
};

template <typename T>
/** TMVVM注册类型Extractor结构体。 */
struct TMVVMRegisterTypeExtractor
{
private:
	using TObjectPtrType = typename ExtractFromTObjectPtr<T>::Type;
	using RawPtrType = typename ExtractFromRawPtr<T>::Type;

public:
	using Type = typename std::conditional<
		!std::is_same_v<TObjectPtrType, void>,

		/** 表示通用 UI中的T对象Ptr类型分支。 */
		TObjectPtrType,
		RawPtrType
	/** 记录type。 */
	>::type;
};

#define REGISTER_MVVM_PROPERTY(ViewModel, Value, FunctionName, CallFunction) \
{ \
	if(ViewModel) \
	{ \
		using ViewModelClass = typename TMVVMRegisterTypeExtractor<decltype(ViewModel)>::Type; \
		ViewModelClass* ViewModelRef = ViewModel; \
		ViewModel->AddFieldValueChangedDelegate \
		( \
			ViewModelClass::FFieldNotificationClassDescriptor::Value, \
			ViewModelClass::FFieldValueChangedDelegate::CreateLambda \
			( \
				[this, ViewModelRef](UObject* InObject, UE::FieldNotification::FFieldId InFieldId) \
				{ \
					FunctionName(ViewModelRef->Value); \
				} \
			) \
		); \
		if(CallFunction) \
		{ \
			FunctionName(ViewModel->Value); \
		} \
	} \
}

#define UNREGISTER_MVVM_PROPERTY(ViewModel) \
	if(ViewModel) \
	{ \
		ViewModel->RemoveAllFieldValueChangedDelegates(this); \
	}
