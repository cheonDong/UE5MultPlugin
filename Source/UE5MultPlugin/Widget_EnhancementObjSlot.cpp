// Fill out your copyright notice in the Description page of Project Settings.

#include "Widget_EnhancementObjSlot.h"
#include "StatEnhancementObjectBase.h"
#include "StatManagementComponent.h"
#include "MyPlayerController.h"

void UWidget_EnhancementObjSlot::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWidget_EnhancementObjSlot::EnhancementPlayerStat(AStatEnhancementObjectBase* target)
{
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	UStatManagementComponent* statManager = Cast<UStatManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UStatManagementComponent>());

	if (PC)
	{
		if (statManager)
		{
			statManager->ComparisonObjType(target);
			UE_LOG(LogTemp, Warning, TEXT("EnhancementPlayerStat"));

			PC->Gold -= target->price;
			PC->OnUpdateMyGold(PC->Gold);
			UE_LOG(LogTemp, Warning, TEXT("%d"), PC->Gold);
			UE_LOG(LogTemp, Warning, TEXT("Success Buy Skill"));
		}
	}

	
}

bool UWidget_EnhancementObjSlot::IsCanBuyObj(AStatEnhancementObjectBase* target)
{
	AMyPlayerController* PC = Cast<AMyPlayerController>(GetWorld()->GetFirstPlayerController());

	if (IsValid(PC) == false)
	{
		return false;
	}

	if (target->price <= PC->Gold)
	{
		return true;
	}
	else
	{
		return false;
	}
}
