// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ActiveSkillLightning.h"
#include "ActiveSkillStorm.h"
#include "ActiveSkillWaterBall.h"
#include "PassiveSkillDefenseArea.h"
#include "Containers/Array.h"
#include "Kismet/GameplayStatics.h"
#include "UE5MultPluginCharacter.h"


void AMyPlayerController::BeginPlay()
{
	SkillDatas[0] = NewObject<AActiveSkillLightning>();
	SkillDatas[1] = NewObject<AActiveSkillStorm>();
	SkillDatas[2] = NewObject<AActiveSkillWaterBall>();
	SkillDatas[3] = NewObject<APassiveSkillDefenseArea>();
	
	SkillShopWidget = CreateWidget<UUserWidget>(GetWorld(), SkillShopWidgetClass);
	SkillShopWidget->AddToViewport();
}

void AMyPlayerController::Tick(float DeltaSeconds)
{
	TArray<AActor*> arrOutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AUE5MultPluginCharacter::StaticClass(), arrOutActors);

	if (sizeof(arrOutActors) == 1)
	{
		
	}
}

void AMyPlayerController::CreateSkillShopWidget()
{
	
}
