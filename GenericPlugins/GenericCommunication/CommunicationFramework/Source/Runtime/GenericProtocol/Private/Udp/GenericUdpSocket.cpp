// Copyright ChenTaiye 2025. All Rights Reserved.

#include "Udp/GenericUdpSocket.h"

#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Common/UdpSocketReceiver.h"
#include "StaticFunctions/StaticFunctions_Convert.h"
#include "Udp/GenericUdpSocketBuilder.h"

UGenericUdpSocket* UGenericUdpSocket::CreateUdpSocket(UGenericUdpSocketBuilder* InBuilder)
{
	if (!InBuilder)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Builder Is InValid"))
		return nullptr;
	}

	UGenericUdpSocket* UdpSocket = NewObject<UGenericUdpSocket>();
	UdpSocket->UpdateUdpSocket(InBuilder);
	return UdpSocket;
}

void UGenericUdpSocket::UpdateUdpSocket(UGenericUdpSocketBuilder* InBuilder)
{
	if (!InBuilder)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Builder Is InValid"))
		return;
	}

	DestroyReceiverSocket();
	DestroySenderSocket();

	Builder = InBuilder;
	SenderSocket = Builder->BuildSenderSocket();
	ReceiverSocket = Builder->BuildReceiverSocket();
}

void UGenericUdpSocket::BeginDestroy()
{
	DestroyReceiverSocket();
	DestroySenderSocket();

	Super::BeginDestroy();
}

bool UGenericUdpSocket::ConnectSender()
{
	if (!SenderSocket)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Sender Socket Is InValid, Use CreateUdpSocket To Create a Valid Udp Socket"));
		OnSenderConnectionErrorEvent.Broadcast(Builder->SendIp, Builder->SendPort);
		return false;
	}

	/* Connect Send Socket */
	TSharedRef<FInternetAddr> SendAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();

	bool bIsValid;
	SendAddr->SetIp(*Builder->SendIp, bIsValid);
	SendAddr->SetPort(Builder->SendPort);

	if (!bIsValid)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Send IP Is InValid"));
		OnSenderConnectionErrorEvent.Broadcast(Builder->SendIp, Builder->SendPort);
		return false;
	}

	if (SenderSocket->Connect(*SendAddr))
	{
		const ESocketConnectionState SocketConnectionState = SenderSocket->GetConnectionState();
		TSharedRef<FInternetAddr> SendBoundAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
		SenderSocket->GetAddress(*SendBoundAddress);
		Builder->SendBoundIp = SendBoundAddress->ToString(false);
		Builder->SendBoundPort = SenderSocket->GetPortNo();

		GenericLOG(GenericLogUdp, Log, TEXT("Connect To Send Socket"));
		OnSenderConnectedEvent.Broadcast(Builder->SendBoundIp, Builder->SendBoundPort);

		return true;
	}

	GenericLOG(GenericLogUdp, Error, TEXT("Fail To Connect Send Socket"));
	OnSenderConnectionErrorEvent.Broadcast(Builder->SendIp, Builder->SendPort);
	return false;
}

bool UGenericUdpSocket::SendMessage(FString InMessage)
{
	if (!SenderSocket)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Socket Is InValid, Call CreateUdpSocket To Create a Valid Udp Socket"));
		OnMessageSentErrorEvent.Broadcast(InMessage);
		return false;
	}

	if (SenderSocket->GetConnectionState() != SCS_Connected)
	{
		GenericLOG(GenericLogUdp, Warning, TEXT("Socket Has Not Been Connected"));
		OnMessageSentErrorEvent.Broadcast(InMessage);
		return false;
	}

	int32 BytesSent = 0;
	TArray<uint8> ByteArray = FStaticFunctions_Convert::ToByteArray(InMessage);

	if (SenderSocket->Send(ByteArray.GetData(), ByteArray.Num(), BytesSent))
	{
		OnMessageSentEvent.Broadcast(InMessage);
		return true;
	}

	GenericLOG(GenericLogUdp, Error, TEXT("Fail To Send Message"));
	OnMessageSentErrorEvent.Broadcast(InMessage);
	return false;
}

bool UGenericUdpSocket::CloseSender()
{
	if (!SenderSocket)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Socket Is InValid, Use CreateUdpSocket To Create a Valid Udp Socket"));
		return false;
	}

	if (SenderSocket->Close())
	{
		const FString ClosedIp = Builder != nullptr ? Builder->SendIp : FString();
		const int32 ClosedPort = Builder != nullptr ? Builder->SendPort : INDEX_NONE;
		DestroySenderSocket();

		GenericLOG(GenericLogUdp, Log, TEXT("Close Send Socket"));
		OnSenderClosedEvent.Broadcast(ClosedIp, ClosedPort);
		return true;
	}

	GenericLOG(GenericLogUdp, Error, TEXT("Fail To Close Send Socket"));
	DestroySenderSocket();
	return false;
}

bool UGenericUdpSocket::ConnectReceiver()
{
	if (!ReceiverSocket)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Socket Is InValid, Use CreateUdpSocket To Create a Valid Udp Socket"));
		OnReceiverConnectionErrorEvent.Broadcast();
		return false;
	}

	FTimespan ThreadWaitTime = FTimespan::FromMilliseconds(100);
	FString ThreadName = FString::Printf(TEXT("UDP RECEIVER-GenericUdpSocket"));
	UDPReceiver = new FUdpSocketReceiver(ReceiverSocket, ThreadWaitTime, *ThreadName);
	UDPReceiver->OnDataReceived().BindUObject(this, &UGenericUdpSocket::HandleOnDataReceived);

	UDPReceiver->Start();

	TSharedRef<FInternetAddr> ReceiveBoundAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	ReceiverSocket->GetAddress(*ReceiveBoundAddress);
	Builder->ReceiveBoundIp = ReceiveBoundAddress->ToString(false);
	Builder->ReceiveBoundPort = ReceiverSocket->GetPortNo();

	OnReceiverConnectedEvent.Broadcast();
	return true;
}

bool UGenericUdpSocket::CloseReceiver()
{
	if (!ReceiverSocket)
	{
		GenericLOG(GenericLogUdp, Error, TEXT("Socket Is InValid, Use CreateUdpSocket To Create a Valid Udp Socket"));
		return false;
	}

	if (!UDPReceiver)
	{
		GenericLOG(GenericLogUdp, Warning, TEXT("UDP Receiver Is InValid"));
	}

	if (ReceiverSocket->Close())
	{
		DestroyReceiverSocket();
		GenericLOG(GenericLogUdp, Log, TEXT("Close Receive Socket"));
		OnReceiverClosedEvent.Broadcast();
		return true;
	}

	GenericLOG(GenericLogUdp, Error, TEXT("Fail To Close Receive Socket"));
	DestroyReceiverSocket();
	return false;
}

void UGenericUdpSocket::DestroySenderSocket()
{
	if (SenderSocket != nullptr)
	{
		SenderSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(SenderSocket);
		SenderSocket = nullptr;
	}
}

void UGenericUdpSocket::DestroyReceiverSocket()
{
	if (UDPReceiver != nullptr)
	{
		UDPReceiver->Stop();
		delete UDPReceiver;
		UDPReceiver = nullptr;
	}

	if (ReceiverSocket != nullptr)
	{
		ReceiverSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ReceiverSocket);
		ReceiverSocket = nullptr;
	}
}

void UGenericUdpSocket::HandleOnDataReceived(const FArrayReaderPtr& DataPtr, const FIPv4Endpoint& Endpoint) const
{
	TArray<uint8> Data;
	Data.AddUninitialized(DataPtr->TotalSize());
	DataPtr->Serialize(Data.GetData(), DataPtr->TotalSize());

	AsyncTask(ENamedThreads::GameThread, [this, Data]()
	          {
		          OnMessageEvent.Broadcast(FStaticFunctions_Convert::ToString(Data));
	          }
	);
}
