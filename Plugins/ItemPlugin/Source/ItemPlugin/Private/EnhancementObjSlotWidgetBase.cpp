// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancementObjSlotWidgetBase.h"
#include "StatEnhancementObjectBase.h"
#include "StatManagementComponent.h"

void UEnhancementObjSlotWidgetBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void UEnhancementObjSlotWidgetBase::EnhancementPlayerStat(AStatEnhancementObjectBase* target)
{
	UStatManagementComponent* statManager = Cast<UStatManagementComponent>(GetWorld()->GetFirstPlayerController()->FindComponentByClass<UStatManagementComponent>());

	if (statManager)
	{
		statManager->ComparisonObjType(target);
		UE_LOG(LogTemp, Warning, TEXT("EnhancementPlayerStat"));
	}
}

