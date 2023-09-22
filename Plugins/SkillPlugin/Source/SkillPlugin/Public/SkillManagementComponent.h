// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SkillManagementComponent.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SKILLPLUGIN_API USkillManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USkillManagementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Data")
	TArray<class ASkillBase*> SkillDatas;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Data")
	TArray<class ASkillBase*> RandomSkills;

	UFUNCTION()
	void SkillLevelUp(class ASkillBase* targetSkill);

	UFUNCTION()
	TArray<class ASkillBase*> GetRandomSkills();

	UFUNCTION(BlueprintCallable, Category = "Data")
	void GetSkill(ASkillBase* Skill);

	UFUNCTION()
	bool IsCanUse(ASkillBase* Skill);

};