// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleSessionWidget.h"
#include "Sessionsubsystem.h"

void USimpleSessionWidget::CreateSession()
{
	if (auto* Sub = GetGameInstance()->GetSubsystem<USessionSubsystem>())
	{
		Sub->CreateLanSession(3);
	}
}