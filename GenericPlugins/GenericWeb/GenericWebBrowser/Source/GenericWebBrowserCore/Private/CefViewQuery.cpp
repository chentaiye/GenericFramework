//
//  Copyright © 2025 SHEEN TECH LAB. All Rights Reserved.
//
#pragma region "Self Header"
#include "CefViewQuery.h"
#pragma endregion

#pragma region <Engine Headers>
#pragma endregion

#pragma region <Platform Headers>
#pragma endregion

#pragma region <STL Headers>
#pragma endregion

#pragma region <Thirdparty Headers>
#pragma endregion

#pragma region <Project Public Headers>
#pragma endregion

#pragma region "Project Private headers"
#pragma endregion

int64
UCefViewQuery::GetId() const
{
  return Id;
}

FString
UCefViewQuery::GetRequest() const
{
  return Request;
}

void
UCefViewQuery::Reply() const
{
}

void
UCefViewQuery::SetIdAndRequest(int64 InId, const FString& InRequest)
{
  Id = InId;
  Request = InRequest;
}

void
UCefViewQuery::MarkAsReplied() const
{
  Replied = true;
}
