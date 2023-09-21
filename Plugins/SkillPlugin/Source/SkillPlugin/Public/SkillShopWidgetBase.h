// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillShopWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class SKILLPLUGIN_API USkillShopWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UListView* SkillList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UListView* StatList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* MaxHp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* MaxMp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* Power;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UTextBlock* Gold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> SkillSlotWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* SkillSlotWidget;

	UFUNCTION()
	void UpdateSkillSlotList();
};
