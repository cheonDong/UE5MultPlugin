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
	// ��ų �迭�� ������ �߰�, ������ ���� ����

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

	// ��ų ����� �����ϸ� �ش� ĳ������ �ַο� ������Ʈ���� ��ų�� �����ϴ� �Լ��� ĳ���Ϳ��� ����

}

