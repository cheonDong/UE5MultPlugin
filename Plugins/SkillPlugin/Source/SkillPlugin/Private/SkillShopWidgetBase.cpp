// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillShopWidgetBase.h"
#include "Components/TextBlock.h"
#include "Components/ListView.h"
#include "SkillBase.h"
#include "SkillSlotWidgetBase.h"

void USkillShopWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));

	SkillList = Cast<UListView>(GetWidgetFromName(TEXT("SkillSlotList")));
	if (SkillList)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkillList"));
	}

	StatList = Cast<UListView>(GetWidgetFromName(TEXT("StatSlotList")));
	if (StatList)
	{
		UE_LOG(LogTemp, Warning, TEXT("StatList"));
	}

	MaxHp = Cast<UTextBlock>(GetWidgetFromName(TEXT("MaxHpVal")));
	if (MaxHp)
	{
		UE_LOG(LogTemp, Warning, TEXT("MaxHp"));
	}

	MaxMp = Cast<UTextBlock>(GetWidgetFromName(TEXT("MaxMpVal")));
	if (MaxMp)
	{
		UE_LOG(LogTemp, Warning, TEXT("MaxMp"));
	}

	Speed = Cast<UTextBlock>(GetWidgetFromName(TEXT("SpeedVal")));
	if (Speed)
	{
		UE_LOG(LogTemp, Warning, TEXT("Speed"));
	}

	Power = Cast<UTextBlock>(GetWidgetFromName(TEXT("PowerVal")));
	if (Power)
	{
		UE_LOG(LogTemp, Warning, TEXT("Power"));
	}

	Gold = Cast<UTextBlock>(GetWidgetFromName(TEXT("GoldT")));
	if (Gold)
	{
		UE_LOG(LogTemp, Warning, TEXT("Gold"));
	}
}

void USkillShopWidgetBase::UpdateSkillSlotList()
{
}

