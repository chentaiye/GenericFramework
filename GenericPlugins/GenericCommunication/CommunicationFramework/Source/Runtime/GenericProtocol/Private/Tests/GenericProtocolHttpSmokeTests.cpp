// Copyright ChenTaiye 2025. All Rights Reserved.

#if WITH_DEV_AUTOMATION_TESTS

#include "Tests/GenericProtocolHttpTestTypes.h"

#include "Http/GenericHttpRequest.h"
#include "Misc/AutomationTest.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGenericProtocolHttpFailureSmokeTest,
	"GenericCommunication.Http.ProcessRequestFailureReturnsUnknownCode",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter
)

bool FGenericProtocolHttpFailureSmokeTest::RunTest(const FString& Parameters)
{
	UGenericHttpRequest* Request = UGenericHttpRequest::CreateHTTPRequest();
	Request->SetURL(TEXT(""));

	UGenericProtocolHttpTestAction* Action = NewObject<UGenericProtocolHttpTestAction>();
	UGenericProtocolHttpTestListener* Listener = NewObject<UGenericProtocolHttpTestListener>();

	Action->OnError.AddDynamic(Listener, &UGenericProtocolHttpTestListener::HandleResponse);
	Action->Prepare(Request);
	Action->Execute();

	TestTrue(TEXT("OnError is broadcast for immediate request failure"), Listener->bReceivedError);
	TestNull(TEXT("Immediate request failure keeps response null"), Listener->Response);
	TestEqual(TEXT("Immediate request failure maps to unknown response code"), Listener->ResponseCode, EHttpResponseCode::CodeUnKnown);

	return true;
}

#endif
