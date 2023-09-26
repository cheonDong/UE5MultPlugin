// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5MultPluginGameMode.h"
#include "UE5MultPluginCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "SkillBase.h"



AUE5MultPluginGameMode::AUE5MultPluginGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	
}

void AUE5MultPluginGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	/*TArray<AActor*> arrOutActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASkillBase::StaticClass(), arrOutActors);

	SetRandomSkills();*/
}


void AUE5MultPluginGameMode::SetRandomSkills()
{
	/*UE_LOG(LogTemp, Warning, TEXT("SetRandomSkills"));
	
	TSubclassOf<ASkillBase> randSkill = SkillDatas[FMath::RandRange(0, SkillDatas.Num() - 1)];

	AddSkills(randSkill);*/
}

void AUE5MultPluginGameMode::AddSkills(TSubclassOf<ASkillBase> SkillData)
{
	/*UE_LOG(LogTemp, Warning, TEXT("%s"), SkillData);*/
}
