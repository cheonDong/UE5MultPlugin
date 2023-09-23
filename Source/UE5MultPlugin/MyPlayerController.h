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

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AActiveSkillLightning* Lightning;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AActiveSkillStorm* Storm;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AActiveSkillWaterBall* WaterBall;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class APassiveSkillDefenseArea* DefenseArea;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	TArray<class AStatEnhancementObjectBase*> StatEnhancementObjs;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AEnhancementMaxHp* EnhancementMaxHp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AEnhancementMaxMp* EnhancementMaxMp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AEnhancementSpeed* EnhancementSpeed;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	class AEnhancementPower* EnhancementPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	class USkillManagementComponent* SkillManager;

	UFUNCTION()
	void CreateSkillShopWidget();

	UFUNCTION()
	void BindSkillSData();

	UFUNCTION()
	void BindEnhancedObjData();

	UFUNCTION()
	void AddSkillDataToSkillManager(TArray<class ASkillBase*>& SkillDatas);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateSkills(const TArray<class ASkillBase*>& SkillDatas);

	void OnUpdateSkills_Implementation(const TArray<class ASkillBase*>& SkillDatas);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnUpdateEnhancementObjs(const TArray<class AStatEnhancementObjectBase*>& SkillDatas);

	void OnUpdateEnhancementObjs_Implementation(const TArray<class AStatEnhancementObjectBase*>& SkillDatas);

};
