// Fill out your copyright notice in the Description page of Project Settings.


#include "ActiveSkillLightning.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Texture2D.h"
#include "MonsterStatComponent.h"
#include "SkillManagementComponent.h"



AActiveSkillLightning::AActiveSkillLightning()
{
	PrimaryActorTick.bCanEverTick = true;

	SkillArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = SkillArea;
	PartX = 150;
	PartY = 150;
	PartZ = 150;
	SkillArea->SetBoxExtent(FVector(PartX, PartY, PartZ));
	SkillArea->SetGenerateOverlapEvents(true);
	SkillArea->SetCollisionProfileName("OverlapAllDynamic");

	SkillBody = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	SkillBody->SetupAttachment(SkillArea);
	SkillSize = 0.5;
	SkillBody->SetRelativeScale3D(FVector(SkillSize, SkillSize, SkillSize));
	SkillBody->SetRelativeLocation(FVector(0.0f, 0.0f, -100.0f));

	static ConstructorHelpers::FObjectFinder<UParticleSystemComponent> ParticleAsset(TEXT("/Game/FXVarietyPack/Particles/P_ky_lightning3.P_ky_lightning3"));
	if (ParticleAsset.Succeeded())
	{
		SkillBody = ParticleAsset.Object;
	}

	SkillMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("SkillMovement"));
	SkillMovement->SetUpdatedComponent(SkillArea);

	SkillMovement->ProjectileGravityScale = 0;
	SkillMovement->InitialSpeed = 500.0f;
	SkillMovement->MaxSpeed = 500.0f;

	Damage = 30.0f;

	Price = 30;

	Cooldown = 10.0f;

	SkillThumbnail = CreateDefaultSubobject<UTexture2D>(TEXT("SKillTumbnail"));

	SkillName = "Lightning";

	SkillDescription = "전방에 낙뢰를 떨어뜨려 넓은 범위의 적에게 데미지를 준다.";


	static ConstructorHelpers::FObjectFinder<UTexture2D> Thumbnail(TEXT("/Game/CraftResourcesIcons/Textures/Tex_feather_01.Tex_feather_01"));
	if (Thumbnail.Succeeded())
	{
		SkillThumbnail = Thumbnail.Object;
	}

	USkillManagementComponent* skillManager = Cast<USkillManagementComponent>(FindComponentByClass<USkillManagementComponent>());

	if (skillManager)
	{
		UE_LOG(LogClass, Warning, TEXT("skillManager"));
		skillManager->AddSkillDataToArr(this);
	}
}

void AActiveSkillLightning::BeginPlay()
{
	Super::BeginPlay();

	

	OnActorBeginOverlap.AddDynamic(this, &AActiveSkillLightning::ProcessBeginOverlap);

	SetLifeSpan(2.0f);
}

void AActiveSkillLightning::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActiveSkillLightning::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority() == false)
		return;

	UE_LOG(LogTemp, Warning, TEXT("MeshBeginOverlap = %s"), *OtherActor->GetName());

	UMonsterStatComponent* monster = Cast<UMonsterStatComponent>(OtherActor->FindComponentByClass<UMonsterStatComponent>());

	if (monster)
	{
		Target = OtherActor;

		ApplySkillDamage();
		UE_LOG(LogClass, Warning, TEXT("ProcessBeginOverlap"));
	}

	// 스킬 레벨업 확인 용
	SkillLevelUp();
}

void AActiveSkillLightning::SkillLevelUp()
{
	Level += 1;
	Damage += 30.0f;
	PartX += 100;
	PartY += 100;
	PartZ += 200;
	SkillSize += 0.5;
	SkillArea->SetBoxExtent(FVector(PartX, PartY, PartZ));
	SkillBody->SetRelativeScale3D(FVector(SkillSize, SkillSize, SkillSize));
}

void AActiveSkillLightning::ApplySkillDamage()
{
	UGameplayStatics::ApplyDamage(Target, Damage, GetWorld()->GetFirstPlayerController(), nullptr, UDamageType::StaticClass());
	UE_LOG(LogClass, Warning, TEXT("ApplyDamage"));
}
