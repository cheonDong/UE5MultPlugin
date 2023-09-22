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

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	TArray<class ASkillBase*> PlayerSkills;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	class AActiveSkillLightning* Lightning;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	class AActiveSkillStorm* Storm;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	class AActiveSkillWaterBall* WaterBall;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	class APassiveSkillDefenseArea* DefenseArea;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	class USkillManagementComponent* SkillManager;

	UFUNCTION()
	void CreateSkillShopWidget();

	UFUNCTION()
	void BindSkillSData();

	UFUNCTION()
	void BindEnhancedItemData();

	UFUNCTION()
	void AddSkillDataToSkillManager(TArray<class ASkillBase*>& SkillDatas);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateSkills(const TArray<class ASkillBase*>& SkillDatas);

	void OnUpdateSkills_Implementation(const TArray<class ASkillBase*>& SkillDatas);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateEnhancementItems(const TArray<class ASkillBase*>& SkillDatas);

	void OnUpdateEnhancementItems_Implementation(const TArray<class ASkillBase*>& SkillDatas);

};
