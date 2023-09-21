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

	/*PlayerSkills[0] = NewObject<AActiveSkillLightning>(this, TEXT("Lightning"));
	PlayerSkills[1] = NewObject<AActiveSkillStorm>(this, TEXT("Storm"));
	PlayerSkills[2] = NewObject<AActiveSkillWaterBall>(this, TEXT("WarterBall"));
	PlayerSkills[3] = NewObject<APassiveSkillDefenseArea>(this, TEXT("DefenseArea"));*/

	AActiveSkillLightning* NewActor = NewObject<AActiveSkillLightning>(GetTransientPackage(), AActiveSkillLightning::StaticClass());
	AActiveSkillStorm* NewActor2 = NewObject<AActiveSkillStorm>(GetTransientPackage(), AActiveSkillStorm::StaticClass());
	AActiveSkillWaterBall* NewActor3 = NewObject<AActiveSkillWaterBall>(GetTransientPackage(), AActiveSkillWaterBall::StaticClass());
	APassiveSkillDefenseArea* NewActor4 = NewObject<APassiveSkillDefenseArea>(GetTransientPackage(), APassiveSkillDefenseArea::StaticClass());

	AllSkillDatas.Add(NewActor);
	AllSkillDatas.Add(NewActor2);
	AllSkillDatas.Add(NewActor3);
	AllSkillDatas.Add(NewActor4);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(NewActor->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(NewActor2->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(NewActor3->SkillName));
	UE_LOG(LogTemp, Warning, TEXT("%s"), *FString(NewActor4->SkillName));

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
}



TArray<class ASkillBase*> USkillManagementComponent::GetSkillDataArr()
{
	return PlayerSkills;
}


TArray<class ASkillBase*> USkillManagementComponent::GetRandomSkills()
{
	// RandomSkills.Empty();
	if (sizeof(AllSkillDatas) <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Fail"));
	}


	for (int i = 0; i < 3; i++)
	{
		if (AllSkillDatas.Num() > 0)
		{
			// ���� �õ� �ʱ�ȭ (�ɼ�)
			FRandomStream RandomStream(FMath::Rand());

			// ������ �ε��� ����
			int32 RandomIndex = RandomStream.RandRange(0, AllSkillDatas.Num() - 1);

			// ������ ��Ҹ� DestinationArray�� �߰�
			RandomSkills.Add(AllSkillDatas[RandomIndex]);

			UE_LOG(LogTemp, Warning, TEXT("%d"), RandomIndex);
		}
	}

	return RandomSkills;

	
}



void USkillManagementComponent::AddSkillDataToArr(ASkillBase* SkillData)
{
	if (SkillData)
	{
		PlayerSkills.Add(SkillData);
	}
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


