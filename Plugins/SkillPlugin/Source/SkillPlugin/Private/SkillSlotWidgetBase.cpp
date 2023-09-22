// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillSlotWidgetBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Engine/Texture2D.h"
#include "SkillManagementComponent.h"
#include "SkillBase.h"
#include "Engine/GameInstance.h"


void USkillSlotWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();

	UE_LOG(LogTemp, Warning, TEXT("NativeConstruct"));

	SKillButton = Cast<UButton>(GetWidgetFromName(TEXT("SkillInfo")));
	if (SKillButton)
	{
		UE_LOG(LogTemp, Warning, TEXT("SKillButton"));
		SKillButton->OnClicked.AddDynamic(this, &USkillSlotWidgetBase::SetSkillOnButton);
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
}

void USkillSlotWidgetBase::SetSkillOnButton()
{
	USkillManagementComponent* SM = Cast<USkillManagementComponent>(GetWorld()->GetFirstPlayerController());

	if (IsValid(SM) == false)
	{
		return;
	}

	//BindSkill(SM->GetRandomSkills());
}

void USkillSlotWidgetBase::BindSkill(ASkillBase* SkillData)
{

}

void USkillSlotWidgetBase::AddSkillToInventory(ASkillBase* targetSkill)
{
	// 스킬 버튼을 누르면 인벤에 해당 스킬의 정보를 넘김
	// 해당 스킬 레벨 업

	UGameInstance* GI = GetWorld()->GetGameInstance();

	if (GI)
	{
		
	}

	USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<USkillManagementComponent>());

	if (skillManager)
	{
		skillManager->SkillLevelUp(targetSkill);
		UE_LOG(LogTemp, Warning, TEXT("%d"), targetSkill->Level);
		UE_LOG(LogTemp, Warning, TEXT("AddSkillToInventory"));
	}

}
