// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
}

TArray<class ASkillBase*> UMyGameInstance::GetSkillDataArr()
{
	return _AllSkillDatas;
}

void UMyGameInstance::AddSkilltoArr(ASkillBase* SkillData)
{
	/*if (SkillData)
	{
		_AllSkillDatas.Add(SkillData);
	}*/
}
