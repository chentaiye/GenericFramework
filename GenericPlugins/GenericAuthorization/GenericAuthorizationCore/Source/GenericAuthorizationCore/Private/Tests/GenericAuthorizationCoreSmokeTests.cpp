// Copyright ChenTaiye 2026. All Rights Reserved.

#if WITH_DEV_AUTOMATION_TESTS

#include "Misc/AutomationTest.h"
#include "Misc/Paths.h"
#include "Settings/AuthorizationSettings.h"
#include "Storage/AuthorizationLicenseStore.h"
#include "Transport/AuthorizationCodec.h"
#include "Verify/AuthorizationVerifier.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericAuthorizationCoreSignatureTest, "GenericFramework.Authorization.Signature", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericAuthorizationCoreStorePathTest, "GenericFramework.Authorization.StorePaths", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FGenericAuthorizationCoreTransportCodeTest, "GenericFramework.Authorization.TransportCode", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FGenericAuthorizationCoreSignatureTest::RunTest(const FString& Parameters)
{
	static const FString VerificationKey(TEXT("UnitTestKey"));
	static const FString ProductId(TEXT("UnitTestProduct"));
	static const FString DeviceId(TEXT("UnitTestDevice"));
	static const FString PackageFingerprint(TEXT("UnitTestPackage"));

	FAuthorizationLicenseToken Token;
	Token.LicenseId = TEXT("LIC-TEST-0001");
	Token.ProductId = ProductId;
	Token.DeviceId = DeviceId;
	Token.PackageFingerprint = PackageFingerprint;
	Token.IssuedAtUnixSeconds = 1000;

	FAuthorizationGrant BaseGrant;
	BaseGrant.ScopeId = TEXT("base_app");
	BaseGrant.ScopeType = EAuthorizationScopeType::BaseApp;
	BaseGrant.GrantType = EAuthorizationGrantType::Timed;
	BaseGrant.IssuedAtUnixSeconds = 1000;
	BaseGrant.ExpireAtUnixSeconds = 2000;
	Token.Grants.Add(BaseGrant);
	Token.Signature = FAuthorizationVerifier::SignLicenseToken(Token, VerificationKey);

	EAuthorizationState ValidationState = EAuthorizationState::Unauthorized;
	FString ValidationMessage;
	TestTrue(TEXT("License token should verify successfully."), FAuthorizationVerifier::VerifyLicenseToken(Token, ProductId, DeviceId, PackageFingerprint, VerificationKey, true, true, ValidationState, ValidationMessage));
	TestEqual(TEXT("Verified token state should be authorized."), ValidationState, EAuthorizationState::Authorized);

	FString SerializedToken;
	FString SerializeError;
	TestTrue(TEXT("License token should serialize successfully."), FAuthorizationVerifier::SerializeLicenseToken(Token, SerializedToken, true, SerializeError));

	FAuthorizationLicenseToken ParsedToken;
	FString ParseError;
	TestTrue(TEXT("License token should parse successfully."), FAuthorizationVerifier::ParseLicenseToken(SerializedToken, ParsedToken, ParseError));
	TestEqual(TEXT("Parsed token id should match."), ParsedToken.LicenseId, Token.LicenseId);

	return true;
}

bool FGenericAuthorizationCoreStorePathTest::RunTest(const FString& Parameters)
{
	const UAuthorizationSettings* Settings = UAuthorizationSettings::Get();
	const FString CommonCacheRoot = FAuthorizationLicenseStore::GetCommonCacheRootDirectory(Settings);
	const FString OnlineCacheDirectory = FAuthorizationLicenseStore::GetCacheDirectory(EAuthorizationSourceType::Online, Settings);
	const FString OfflineCacheDirectory = FAuthorizationLicenseStore::GetCacheDirectory(EAuthorizationSourceType::Offline, Settings);

	TestTrue(TEXT("Authorization cache should use a common user directory instead of ProjectSavedDir."), !CommonCacheRoot.StartsWith(FPaths::ProjectSavedDir()));
	TestTrue(TEXT("Online cache directory should contain the configured online cache folder name."), OnlineCacheDirectory.Contains(Settings->OnlineCacheDirectoryName));
	TestTrue(TEXT("Offline cache directory should contain the configured offline cache folder name."), OfflineCacheDirectory.Contains(Settings->OfflineCacheDirectoryName));
	TestNotEqual(TEXT("Online and offline cache directories should be different."), OnlineCacheDirectory, OfflineCacheDirectory);

	return true;
}

bool FGenericAuthorizationCoreTransportCodeTest::RunTest(const FString& Parameters)
{
	static const FString VerificationKey(TEXT("UnitTestKey"));
	static const FString ProductId(TEXT("UnitTestProduct"));
	static const FString DeviceId(TEXT("UnitTestDevice"));
	static const FString PackageFingerprint(TEXT("UnitTestPackage"));

	const FString RequestCode = FAuthorizationCodec::BuildAuthorizationRequestCode(ProductId, DeviceId, PackageFingerprint, VerificationKey);
	TestTrue(TEXT("Request code should be encoded."), FAuthorizationCodec::IsAuthorizationRequestCode(RequestCode));

	FAuthorizationRequestCodePayload RequestPayload;
	FString RequestError;
	TestTrue(TEXT("Request code should decode successfully."), FAuthorizationCodec::ParseAuthorizationRequestCode(RequestCode, VerificationKey, RequestPayload, RequestError));
	TestEqual(TEXT("Decoded request product should match."), RequestPayload.ProductId, ProductId);
	TestEqual(TEXT("Decoded request device should match."), RequestPayload.DeviceId, DeviceId);
	TestEqual(TEXT("Decoded request package fingerprint should match."), RequestPayload.PackageFingerprint, PackageFingerprint);

	FAuthorizationLicenseToken Token;
	Token.LicenseId = TEXT("LIC-TEST-0002");
	Token.ProductId = ProductId;
	Token.DeviceId = DeviceId;
	Token.PackageFingerprint = PackageFingerprint;
	Token.IssuedAtUnixSeconds = 2000;

	FAuthorizationGrant Grant;
	Grant.ScopeId = TEXT("base_app");
	Grant.ScopeType = EAuthorizationScopeType::BaseApp;
	Grant.GrantType = EAuthorizationGrantType::Permanent;
	Grant.IssuedAtUnixSeconds = 2000;
	Token.Grants.Add(Grant);
	Token.Signature = FAuthorizationVerifier::SignLicenseToken(Token, VerificationKey);

	const FString LicenseCode = FAuthorizationCodec::BuildLicenseTokenCode(Token, VerificationKey);
	TestTrue(TEXT("License code should be encoded."), FAuthorizationCodec::IsLicenseTokenCode(LicenseCode));

	FString DecodedTokenJson;
	FString DecodeError;
	TestTrue(TEXT("License code should decode successfully."), FAuthorizationCodec::TryDecodeLicenseTokenInput(LicenseCode, VerificationKey, DecodedTokenJson, DecodeError));
	TestTrue(TEXT("Decoded token json should not expose the opaque prefix."), !DecodedTokenJson.StartsWith(TEXT("GAL1-")));

	FAuthorizationLicenseToken ParsedToken;
	FString ParseError;
	TestTrue(TEXT("Decoded token should parse successfully."), FAuthorizationVerifier::ParseLicenseToken(DecodedTokenJson, ParsedToken, ParseError));
	TestEqual(TEXT("Decoded token id should match."), ParsedToken.LicenseId, Token.LicenseId);

	return true;
}

#endif
