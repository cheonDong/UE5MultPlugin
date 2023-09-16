// Fill out your copyright notice in the Description page of Project Settings.


#include "ActiveSkillStorm.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Texture2D.h"

AActiveSkillStorm::AActiveSkillStorm()
{
	PrimaryActorTick.bCanEverTick = true;

	SkillArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = SkillArea;
	PartX = 100;
	PartY = 100;
	PartZ = 200;
	SkillArea->SetBoxExtent(FVector(PartX, PartY, PartZ));
	SkillArea->SetGenerateOverlapEvents(true);
	SkillArea->SetCollisionProfileName("OverlapAllDynamic");

	SkillBody = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	SkillBody->SetupAttachment(SkillArea);
	SkillSize = 0.5;
	SkillBody->SetRelativeScale3D(FVector(SkillSize, SkillSize, SkillSize));
	SkillBody->SetRelativeLocation(FVector(0.0f, 0.0f, -200.0f));

	SkillMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("SkillMovement"));
	SkillMovement->SetUpdatedComponent(SkillArea);

	SkillMovement->ProjectileGravityScale = 0;
	SkillMovement->InitialSpeed = 300.0f;
	SkillMovement->MaxSpeed = 300.0f;

	Damage = 30.0f;

	Price = 30;

	Cooldown = 10.0f;

	SkillThumbnail = CreateDefaultSubobject<UTexture2D>(TEXT("SKillTumbnail"));
}

void AActiveSkillStorm::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AActiveSkillStorm::ProcessBeginOverlap);

	// SetLifeSpan(10.0f);
}

void AActiveSkillStorm::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AActiveSkillStorm::ProcessBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (HasAuthority() == false)
		return;

	UE_LOG(LogTemp, Warning, TEXT("MeshBeginOverlap = %s"), *OtherActor->GetName());

	/*AMultPjProCharacter* target = Cast<AMultPjProCharacter>(OtherActor);
	Target = target;

	if (target)
	{
		ApplySkillDamage();
	}*/

	SkillLevelUp();
}

void AActiveSkillStorm::SkillLevelUp()
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

void AActiveSkillStorm::ApplySkillDamage()
{
	UGameplayStatics::ApplyDamage(Target, Damage, GetWorld()->GetFirstPlayerController(), nullptr, UDamageType::StaticClass());
	UE_LOG(LogClass, Warning, TEXT("ApplyDamage"));

	// ƽ������ ����
	FTimerManager& timerManager = GetWorld()->GetTimerManager();
	timerManager.SetTimer(Th_ProcessBeginOverlap, this, &AActiveSkillStorm::ApplySkillDamage, 0.5f, false);
}
