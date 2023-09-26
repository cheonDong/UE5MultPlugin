// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_SkillSlot.generated.h"

/**
 * 
 */
UCLASS()
class UE5MULTPLUGIN_API UWidget_SkillSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable)
	void AddSkillToInventory(class ASkillBase* target);

	UFUNCTION(BlueprintCallable)
	bool IsCanBuySkill(class ASkillBase* target);

};
