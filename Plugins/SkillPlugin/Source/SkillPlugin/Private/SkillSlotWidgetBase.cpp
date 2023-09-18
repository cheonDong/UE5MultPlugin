// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSlotWidgetBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"

void USkillSlotWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));

	SKillButton = Cast<UButton>(GetWidgetFromName(TEXT("SkillInfo")));
	if (SKillButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("SKillButton"));
		SKillButton->OnClicked.AddDynamic(this, &USkillSlotWidgetBase::AddSkillToInventory);
	}

	SkillName = Cast<UTextBlock>(GetWidgetFromName(TEXT("SkillNameT")));
	if (SkillName)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkillName"));
	}

	SkillDescription = Cast<UTextBlock>(GetWidgetFromName(TEXT("SkillDescriptionT")));
	if (SkillName)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkillDescription"));
	}

	Cost = Cast<UTextBlock>(GetWidgetFromName(TEXT("CostT")));
	if (Cost)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cost"));
	}

	SkillIcon = Cast<UTexture2D>(GetWidgetFromName(TEXT("SkillTHumbnailImage")));
	if (SkillIcon)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkillIcon"));
	}

	SetSkillOnButton();
}

void USkillSlotWidgetBase::SetSkillOnButton()
{
	// ��ų ����ü�� �����ͼ� �������� ��ų ��ġ
}

void USkillSlotWidgetBase::AddSkillToInventory()
{
	// ��ų ��ư�� ������ �κ��� �ش� ��ų�� ������ �ѱ�
	// �ش� ��ų ���� ��
}
