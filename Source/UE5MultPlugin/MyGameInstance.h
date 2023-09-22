// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE5MULTPLUGIN_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();
	
public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	TArray<class ASkillBase*> _AllSkillDatas;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	int32 SkillLevel = 0;

	UFUNCTION()
	TArray<class ASkillBase*> GetSkillDataArr();

	UFUNCTION()
	void AddSkilltoArr(ASkillBase* SkillData);
};
