// Fill out your copyright notice in the Description page of Project Settings.


#include "PassiveSkillDefenseArea.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Texture2D.h"
// #include "UE5MultPlugin/UE5MultPluginCharacter.h"



APassiveSkillDefenseArea::APassiveSkillDefenseArea()
{
	PrimaryActorTick.bCanEverTick = true;

	SkillArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = SkillArea;
	SkillArea->SetBoxExtent(FVector(130, 130, 130));
	SkillArea->SetGenerateOverlapEvents(true);
	SkillArea->SetCollisionProfileName("OverlapAllDynamic");

	SkillBody = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	SkillBody->SetupAttachment(SkillArea);
	SkillBody->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));

	Damage = 50.0f;

	Price = 50;

	SkillThumbnail = CreateDefaultSubobject<UTexture2D>(TEXT("SKillTumbnail"));
}

void APassiveSkillDefenseArea::BeginPlay()
{
	Super::BeginPlay();
	
	OnActorBeginOverlap.AddDynamic(this, &APassiveSkillDefenseArea::ProcessBeginOverlap);
}

void APassiveSkillDefenseArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APassiveSkillDefenseArea::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority() == false)
		return;

	UE_LOG(LogTemp, Warning, TEXT("MeshBeginOverlap = %s"), *OtherActor->GetName());

	/*AUE5MultPluginCharacter* target = Cast<AUE5MultPluginCharacter>(OtherActor);

	Target = target;

	if (target)
	{
		SkillArea->SetSimulatePhysics(false);

		AttachToActor(target, FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("spine_01"));
	}*/
}

void APassiveSkillDefenseArea::ApplySkillDamage()
{
	UGameplayStatics::ApplyDamage(Target, Damage, GetWorld()->GetFirstPlayerController(), nullptr, UDamageType::StaticClass());
	UE_LOG(LogClass, Warning, TEXT("ApplyDamage"));

	// 틱데미지 구현
	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(Th_ProcessBeginOverlap, this, &APassiveSkillDefenseArea::ApplySkillDamage, 0.5f, false);
}
