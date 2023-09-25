// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnhancementObjSlotWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class ITEMPLUGIN_API UEnhancementObjSlotWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void EnhancementPlayerStat(class AStatEnhancementObjectBase* target);
};
