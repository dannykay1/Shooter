// Copyright Danny Kay

#pragma once
#include "Kismet/KismetSystemLibrary.h"

namespace ShooterDebug
{
	static void Print(const FString& Msg, const int32 InKey = -1, const FColor& InColor = FColor::MakeRandomColor())
	{
		if (GEngine == nullptr)
		{
			return;
		}

		GEngine->AddOnScreenDebugMessage(InKey, 7.0f, InColor, Msg);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
	}
}
