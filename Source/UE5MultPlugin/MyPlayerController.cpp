// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ActiveSkillLightning.h"
#include "ActiveSkillStorm.h"
#include "ActiveSkillWaterBall.h"
#include "PassiveSkillDefenseArea.h"
#include "Containers/Array.h"
#include "Kismet/GameplayStatics.h"
#include "SkillManagementComponent.h"
#include "SkillShopWidgetBase.h"
#include "UE5MultPluginCharacter.h"
#include "Net/UnrealNetwork.h"
#include "SkillBase.h"
#include "Kismet/GameplayStatics.h"


void AMyPlayerController::BeginPlay()
{
	/*SkillDatas[0] = NewObject<AActiveSkillLightning>();
	SkillDatas[1] = NewObject<AActiveSkillStorm>();
	SkillDatas[2] = NewObject<AActiveSkillWaterBall>();
	SkillDatas[3] = NewObject<APassiveSkillDefenseArea>();*/
	

	SkillShopWidget = CreateWidget<UUserWidget>(GetWorld(), SkillShopWidgetClass);
	CreateSkillShopWidget();
	
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	TArray<AActor*> arrOutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AUE5MultPluginCharacter::StaticClass(), arrOutActors);

	if (sizeof(arrOutActors) == 1)
	{
		
	}
}

AMyPlayerController::AMyPlayerController()
{
}

void AMyPlayerController::CreateSkillShopWidget()
{
	
	SkillShopWidget->AddToViewport();

	//USkillManagementComponent* SkillManager = Cast<USkillManagementComponent>(GetCharacter()->FindComponentByClass<USkillManagementComponent>());
	//if (SkillManager == nullptr)
	//{
	//	return;
	//}

	this->SetInputMode(FInputModeGameAndUI());
	this->bShowMouseCursor = true;

	/*USkillShopWidgetBase* skillShop = Cast<USkillShopWidgetBase>(SkillShopWidget);
	if (skillShop == nullptr)
	{
		return;
	}

	skillShop->UpdateSkillSlotList();*/

	BindSkillSData();
}

void AMyPlayerController::BindSkillSData()
{
	AUE5MultPluginCharacter* player0 = Cast<AUE5MultPluginCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (player0)
	{
		USkillManagementComponent* skillManaer = Cast<USkillManagementComponent>(player0->FindComponentByClass<USkillManagementComponent>());

		if (skillManaer)
		{

			TArray<class ASkillBase*> Mid = skillManaer->GetRandomSkills();

			OnUpdateSkills(Mid);

			// Mid 인덱스가 0에서 0이라고 오류 발생. 스킬 매니ㅓ에서 못가져오는듯

			for (int i = 0; i < 3; i++)
			{
				// UE_LOG(LogTemp, Warning, TEXT("%f"), Mid[i]->PartZ);
			}

			UE_LOG(LogTemp, Warning, TEXT("Bind Success"));
		}
	}
	
}

void AMyPlayerController::OnUpdateSkills_Implementation(const TArray<class ASkillBase*>& SkillDatas)
{
}
