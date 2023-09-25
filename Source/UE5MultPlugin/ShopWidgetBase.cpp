// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopWidgetBase.h"
#include "StatManagementComponent.h"
#include "SkillManagementComponent.h"
#include "Net/UnrealNetwork.h"
#include "Blueprint/UserWidget.h"

void UShopWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UShopWidgetBase::BindMyStatManagement()
{
	UStatManagementComponent* StatManager = Cast<UStatManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UStatManagementComponent>());

	if (StatManager)
	{
		USkillManagementComponent* SkillManager = Cast<USkillManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<USkillManagementComponent>());
		
		if (SkillManager)
		{
			UE_LOG(LogTemp, Warning, TEXT("BindMyStatManagement"));

			StatManager->Fuc_Dele_UpdateHp.AddDynamic(this, &UShopWidgetBase::OnUpdateMyMaxHp);
			OnUpdateMyMaxHp(StatManager->CurHp, StatManager->MaxHp);

			StatManager->Fuc_Dele_UpdateMp.AddDynamic(this, &UShopWidgetBase::OnUpdateMyMaxMp);
			OnUpdateMyMaxMp(StatManager->CurMp, StatManager->MaxMp);

			StatManager->Fuc_Dele_UpdateSpeed.AddDynamic(this, &UShopWidgetBase::OnUpdateMySpeed);
			OnUpdateMySpeed(StatManager->Speed);

			StatManager->Fuc_Dele_UpdatePower.AddDynamic(this, &UShopWidgetBase::OnUpdateMyPower);
			OnUpdateMyPower(StatManager->Power);

			return;
		}
	}

	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(th_BindMyStatManager, this, &UShopWidgetBase::BindMyStatManagement, 0.1f, false);
}

void UShopWidgetBase::OnUpdateMyMaxHp_Implementation(float CurHp, float MaxHp)
{
}

void UShopWidgetBase::OnUpdateMyMaxMp_Implementation(float CurHp, float MaxHp)
{
}

void UShopWidgetBase::OnUpdateMySpeed_Implementation(float Speed)
{
}

void UShopWidgetBase::OnUpdateMyPower_Implementation(float Power)
{
}
