// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManagementComponent.h"
#include "SkillBase.h"

// Sets default values for this component's properties
USkillManagementComponent::USkillManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USkillManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USkillManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USkillManagementComponent::GetSkill(ASkillBase* Skill)
{
	// 스킬 배열에 없으면 추가, 있으면 레벨 증가

	if (Skill == nullptr)
	{
		return;
	}
	
	if (PlayerSkills.Find(Skill) == false)
	{
		PlayerSkills.Add(Skill);
	}
	else
	{
		Skill->Level += 1;
	}
}

bool USkillManagementComponent::IsCanUse(ASkillBase* Skill)
{
	if (Skill == nullptr)
	{
		return false;
	}
	
	if (Skill->Level >= 1)
	{
		return true;
	}

	return false;

	// 스킬 사용이 가능하며 해당 캐릭터의 애로우 컴포넌트에서 스킬을 스폰하는 함수를 캐릭터에서 실행

}

