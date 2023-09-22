// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManagementComponent.h"
#include "SkillBase.h"
#include "ActiveSkillLightning.h"
#include "ActiveSkillStorm.h"
#include "ActiveSkillWaterBall.h"
#include "PassiveSkillDefenseArea.h"
#include "Containers/Array.h"
#include "Net/UnrealNetwork.h"
#include "Runtime/Core/Public/Math/RandomStream.h"  // ���� �Լ��� ����ϱ� ���� ���

// Sets default values for this component's properties
USkillManagementComponent::USkillManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void USkillManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	

	/*GetRandomSkills();

	for (int i = 0; i < 3; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("%f"), RandomSkills[i]->PartZ);
	}*/
	

}



// Called every frame
void USkillManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	//if(Lightning)
	// UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(Lightning->SkillName));
}




void USkillManagementComponent::SkillLevelUp(class ASkillBase* targetSkill)
{
	for (int i = 0; i < SkillDatas.Num(); i++)
	{
		if (SkillDatas[i] == targetSkill)
		{
			SkillDatas[i]->Level += 1;
			UE_LOG(LogTemp, Warning, TEXT("LevelUp"));
		}
	}
}

TArray<class ASkillBase*> USkillManagementComponent::GetRandomSkills()
{
	UE_LOG(LogTemp, Warning, TEXT("GetRandomSkills Start"));

	// RandomSkills.Empty();
	if (SkillDatas.Num() <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail"));
	}

	RandomSkills.Empty();

	for (int i = 0; i < SkillDatas.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("for AllSkillDatas Start"));

		if (SkillDatas.Num() > 0)
		{
			// ���� �õ� �ʱ�ȭ (�ɼ�)
			FRandomStream RandomStream(FMath::Rand());

			// ������ �ε��� ����
			int32 RandomIndex = RandomStream.RandRange(0, SkillDatas.Num() - 1);

			// ������ ��Ҹ� DestinationArray�� �߰�
			RandomSkills.Add(SkillDatas[RandomIndex]);

			UE_LOG(LogTemp, Warning, TEXT("%d"), RandomIndex);
		}
	}

	return RandomSkills;
}



void USkillManagementComponent::GetSkill(ASkillBase* Skill)
{
	// ��ų �迭�� ������ �߰�, ������ ���� ����

	if (Skill == nullptr)
	{
		return;
	}
	
	if (SkillDatas.Find(Skill) == false)
	{
		SkillDatas.Add(Skill);
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


