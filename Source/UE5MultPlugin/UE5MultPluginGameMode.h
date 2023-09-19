// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UE5MultPluginGameMode.generated.h"

UCLASS(minimalapi)
class AUE5MultPluginGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUE5MultPluginGameMode();

	virtual void Tick(float DeltaSeconds) override;

public:
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SKillData")
	TArray<class ASkillBase*> SkillDatas;*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	TArray<TSubclassOf<class ASkillBase>> SkillDatas;

	UFUNCTION()
	void SetRandomSkills();

	UFUNCTION()
	void AddSkills(TSubclassOf<ASkillBase> SkillData);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Data")
	float Time = 30.0f;

	
	
};



