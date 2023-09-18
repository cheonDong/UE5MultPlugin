// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillSlotWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class SKILLPLUGIN_API USkillSlotWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UButton* SKillButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* SkillName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* SkillDescription;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* Cost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTexture2D* SkillIcon;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Custom)
	//class FButtonClick* OnClickContinue;

	//UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = Custom)
	//class FButtonClick* OnClickExit;

public:
	UFUNCTION()
	void SetSkillOnButton();

	UFUNCTION()
	void AddSkillToInventory();
};
