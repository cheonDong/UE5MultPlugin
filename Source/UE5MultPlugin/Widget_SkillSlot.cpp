// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_SkillSlot.h"
#include "SkillManagementComponent.h"
#include "SkillBase.h"
#include "MyPlayerController.h"


void UWidget_SkillSlot::NativeConstruct()
{
	Super::NativeConstruct();

}

void UWidget_SkillSlot::AddSkillToInventory(ASkillBase* targetSkill)
{
	// 스킬 버튼을 누르면 인벤에 해당 스킬의 정보를 넘김
	// 해당 스킬 레벨 업
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<USkillManagementComponent>());

	if (PC)
	{
		if (skillManager)
		{
			skillManager->SkillLevelUp(targetSkill);
			UE_LOG(LogTemp, Warning, TEXT("%d"), targetSkill->Level);
			UE_LOG(LogTemp, Warning, TEXT("AddSkillToInventory"));

			PC->Gold -= targetSkill->Price;
			PC->OnUpdateMyGold(PC->Gold);
			UE_LOG(LogTemp, Warning, TEXT("%d"), PC->Gold);
			UE_LOG(LogTemp, Warning, TEXT("Success Buy Skill"));
		}
	}
	

}

bool UWidget_SkillSlot::IsCanBuySkill(ASkillBase* target)
{
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	if (IsValid(PC) == false)
	{
		return false;
	}

	if (target->Price <= PC->Gold)
	{
		return true;
	}
	else
	{
		return false;
	}
}

