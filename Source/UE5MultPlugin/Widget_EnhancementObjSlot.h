// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_EnhancementObjSlot.generated.h"

/**
 * 
 */
UCLASS()
class UE5MULTPLUGIN_API UWidget_EnhancementObjSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void EnhancementPlayerStat(class AStatEnhancementObjectBase* target);

	UFUNCTION(BlueprintCallable)
	bool IsCanBuyObj(class AStatEnhancementObjectBase* target);
};
