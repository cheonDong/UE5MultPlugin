// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "SkillBase.h"
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
#include "StatEnhancementObjectBase.h"
#include "EnhancementMaxHp.h"
#include "EnhancementMaxMp.h"
#include "EnhancementPower.h"
#include "EnhancementSpeed.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerSkills.Empty();

	Lightning = NewObject<AActiveSkillLightning>(ASkillBase::StaticClass(), AActiveSkillLightning::StaticClass());
	Storm = NewObject<AActiveSkillStorm>(ASkillBase::StaticClass(), AActiveSkillStorm::StaticClass());
	WaterBall = NewObject<AActiveSkillWaterBall>(ASkillBase::StaticClass(), AActiveSkillWaterBall::StaticClass());
	DefenseArea = NewObject<APassiveSkillDefenseArea>(ASkillBase::StaticClass(), APassiveSkillDefenseArea::StaticClass());

	PlayerSkills.Add(Lightning);
	PlayerSkills.Add(Storm);
	PlayerSkills.Add(WaterBall);
	PlayerSkills.Add(DefenseArea);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(Lightning->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(Storm->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(WaterBall->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(DefenseArea->SkillName));

	StatEnhancementObjs.Empty();

	EnhancementMaxHp = NewObject<AEnhancementMaxHp>(ASkillBase::StaticClass(), AEnhancementMaxHp::StaticClass());
	EnhancementMaxMp = NewObject<AEnhancementMaxMp>(ASkillBase::StaticClass(), AEnhancementMaxMp::StaticClass());
	EnhancementSpeed = NewObject<AEnhancementSpeed>(ASkillBase::StaticClass(), AEnhancementSpeed::StaticClass());
	EnhancementPower = NewObject<AEnhancementPower>(ASkillBase::StaticClass(), AEnhancementPower::StaticClass());

	StatEnhancementObjs.Add(EnhancementMaxHp);
	StatEnhancementObjs.Add(EnhancementMaxMp);
	StatEnhancementObjs.Add(EnhancementSpeed);
	StatEnhancementObjs.Add(EnhancementPower);

	SkillShopWidget = CreateWidget<UUserWidget>(GetWorld(), SkillShopWidgetClass);
	AddSkillDataToSkillManager(PlayerSkills);

	CreateSkillShopWidget();

}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	
	Super::Tick(DeltaSeconds);
}

AMyPlayerController::AMyPlayerController()
{
	SkillManager = CreateDefaultSubobject<USkillManagementComponent>(TEXT("SkillManager"));
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
	BindEnhancedObjData();
}

void AMyPlayerController::BindSkillSData()
{
	AUE5MultPluginCharacter* player0 = Cast<AUE5MultPluginCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	
	if (player0)
	{
		// USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(player0->FindComponentByClass<USkillManagementComponent>());
		USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(this->FindComponentByClass<USkillManagementComponent>());

		if (skillManager)
		{

			TArray<class ASkillBase*> RandSkills = skillManager->GetRandomSkills();

			OnUpdateSkills(RandSkills);

			// Mid 인덱스가 0에서 0이라고 오류 발생. 스킬 매니ㅓ에서 못가져오는듯

			for (int i = 0; i < RandSkills.Num(); i++)
			{
				UE_LOG(LogTemp, Warning, TEXT("%f"), RandSkills[i]->PartZ);
			}

			UE_LOG(LogTemp, Warning, TEXT("BindSkillSData Success"));
		}
	}
	
}

void AMyPlayerController::BindEnhancedObjData()
{
	AUE5MultPluginCharacter* player0 = Cast<AUE5MultPluginCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (player0)
	{
		OnUpdateEnhancementObjs(StatEnhancementObjs);

		for (int i = 0; i < StatEnhancementObjs.Num(); i++)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(StatEnhancementObjs[i]->ObjName));
		}

		UE_LOG(LogTemp, Warning, TEXT("BindEnhancedItemData Success"));
	}
}

void AMyPlayerController::AddSkillDataToSkillManager(TArray<class ASkillBase*>& SkillDatas)
{
	AUE5MultPluginCharacter* player0 = Cast<AUE5MultPluginCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

	if (player0)
	{
		// USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(player0->FindComponentByClass<USkillManagementComponent>());
		USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(this->FindComponentByClass<USkillManagementComponent>());

		if (skillManager)
		{
			skillManager->SkillDatas = SkillDatas;
		}
	}
}

void AMyPlayerController::OnUpdateSkills_Implementation(const TArray<class ASkillBase*>& SkillDatas)
{
}

void AMyPlayerController::OnUpdateEnhancementObjs_Implementation(const TArray<class AStatEnhancementObjectBase*>& SkillDatas)
{
}
