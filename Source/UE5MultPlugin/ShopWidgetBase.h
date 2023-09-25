// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class UE5MULTPLUGIN_API UShopWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void BindMyStatManagement();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyMaxHp(float CurHp, float MaxHp);

	void OnUpdateMyMaxHp_Implementation(float CurHp, float MaxHp);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyMaxMp(float CurMp, float MaxMp);

	void OnUpdateMyMaxMp_Implementation(float CurHp, float MaxHp);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMySpeed(float Speed);

	void OnUpdateMySpeed_Implementation(float Speed);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateMyPower(float Power);

	void OnUpdateMyPower_Implementation(float Power);

	

	FTimerHandle th_BindMyStatManager;
};
