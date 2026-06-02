// Copyright ChenTaiye 2025. All Rights Reserved.

#if WITH_DEV_AUTOMATION_TESTS

#include "NativeAPIInterface.h"
#include "NativeAPITypes.h"

#include "GameFramework/Actor.h"
#include "Misc/AutomationTest.h"

namespace NativeAPISmokeTestPrivate
{
	/** 捕获模拟 JSON 分发结果的轻量接收器，用于验证接口默认链路会把有效消息转换为 Payload。 */
	class FTestNativeAPIReceiver : public INativeAPIInterface
	{
	public:
		/** 统计 ProcessingNativeAPI 被触发的次数，测试用它确认无效 JSON 不会进入分发链路。 */
		mutable int32 DispatchCount = 0;

		/** 保存最近一次收到的 Payload，测试用它校验 EntityClass 和 API 任务解析结果。 */
		mutable FNativeAPIPayload LastPayload;

		virtual void ProcessingNativeAPI(const FNativeAPIPayload& Payload) const override
		{
			++DispatchCount;
			LastPayload = Payload;
		}
	};
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FNativeAPISimulationSmokeTest,
	"GenericCommunication.NativeAPI.SimulationDispatchesValidPayload",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FNativeAPISimulationSmokeTest::RunTest(const FString& Parameters)
{
	NativeAPISmokeTestPrivate::FTestNativeAPIReceiver Receiver;

	Receiver.SendSimulationNativeAPIMessage(TEXT("{\"Message\":\"NotNativeAPI\"}"));
	TestEqual(TEXT("Non-NativeAPI json is ignored"), Receiver.DispatchCount, 0);

	const FString NativeAPIJson = FString::Printf(
		TEXT("{\"EntityClass\":\"%s\",\"API_Ping\":{}}"),
		*AActor::StaticClass()->GetClassPathName().ToString()
	);

	Receiver.SendSimulationNativeAPIMessage(NativeAPIJson);
	TestEqual(TEXT("Valid NativeAPI json dispatches exactly once"), Receiver.DispatchCount, 1);
	TestTrue(TEXT("Captured payload is valid"), Receiver.LastPayload.IsValid());
	TestEqual(TEXT("Captured entity class path matches json"), Receiver.LastPayload.GetClassPath().ToString(), AActor::StaticClass()->GetClassPathName().ToString());

	TArray<FNativeAPITask> Tasks;
	Receiver.LastPayload.GetTaskList(Tasks);
	TestEqual(TEXT("Captured task count"), Tasks.Num(), 1);
	if (Tasks.Num() == 1)
	{
		TestEqual(TEXT("Captured task name"), Tasks[0].FuncName, FName(TEXT("API_Ping")));
	}

	return true;
}

#endif
