// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UE5MULTPLUGIN_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	AMyPlayerController();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class UUserWidget> SkillShopWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* SkillShopWidget;

	UFUNCTION()
	void CreateSkillShopWidget();

	UFUNCTION()
	void BindSkillSData();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateSkills(const TArray<class ASkillBase*>& SkillDatas);

	void OnUpdateSkills_Implementation(const TArray<class ASkillBase*>& SkillDatas);

};