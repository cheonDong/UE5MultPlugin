// Fill out your copyright notice in the Description page of Project Settings.


#include "StatManagementComponent.h"
#include "Net/UnrealNetwork.h"
#include "StatEnhancementObjectBase.h"
#include "EnhancementMaxHp.h"
#include "EnhancementMaxMp.h"
#include "EnhancementPower.h"
#include "EnhancementSpeed.h"

// Sets default values for this component's properties
UStatManagementComponent::UStatManagementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatManagementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatManagementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatManagementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UStatManagementComponent, CurHp);
	DOREPLIFETIME(UStatManagementComponent, MaxHp);
	DOREPLIFETIME(UStatManagementComponent, CurMp);
	DOREPLIFETIME(UStatManagementComponent, MaxMp);
	DOREPLIFETIME(UStatManagementComponent, Speed);
	DOREPLIFETIME(UStatManagementComponent, Power);
}

void UStatManagementComponent::OnRep_CurHp()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_CurHp"));
	if (Fuc_Dele_UpdateHp.IsBound())
		Fuc_Dele_UpdateHp.Broadcast(CurHp, MaxHp);
}

void UStatManagementComponent::OnRep_MaxHp()
{
	if (Fuc_Dele_UpdateHp.IsBound())
		Fuc_Dele_UpdateHp.Broadcast(CurHp, MaxHp);
}

void UStatManagementComponent::OnRep_CurMp()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_CurMp"));
	if (Fuc_Dele_UpdateMp.IsBound())
		Fuc_Dele_UpdateMp.Broadcast(CurHp, MaxHp);
}

void UStatManagementComponent::OnRep_MaxMp()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_MaxMp"));
	if (Fuc_Dele_UpdateMp.IsBound())
		Fuc_Dele_UpdateMp.Broadcast(CurHp, MaxHp);
}


void UStatManagementComponent::OnRep_Speed()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_MaxSpeed"));
	if (Fuc_Dele_UpdateSpeed.IsBound())
		Fuc_Dele_UpdateSpeed.Broadcast(Speed);
}

void UStatManagementComponent::OnRep_Power()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_MaxPower"));
	if (Fuc_Dele_UpdatePower.IsBound())
		Fuc_Dele_UpdatePower.Broadcast(Power);
}

void UStatManagementComponent::ComparisonObjType(AStatEnhancementObjectBase* target)
{
	if (target == HpVal)
	{
		IncreaseMaxHp();
	}
	else if (target == MpVal)
	{
		IncreaseMaxMp();
	}
	else if (target == SpeedVal)
	{
		IncreaseSpeed();
	}
	else if (target == PowerVal)
	{
		IncreasePower();
	}
}

void UStatManagementComponent::IncreaseMaxHp()
{
	MaxHp += 5.0f;

	OnRep_MaxHp();
}

void UStatManagementComponent::RecurberyHp()
{

	CurHp = CurHp + 10.0f;
	CurHp = FMath::Clamp(CurHp, 0.0f, MaxHp);

	UE_LOG(LogTemp, Warning, TEXT("%f"), CurHp);

	OnRep_CurHp();
}

void UStatManagementComponent::IncreaseMaxMp()
{
	MaxMp += 5.0f;

	OnRep_MaxMp();
}

void UStatManagementComponent::IncreaseSpeed()
{
	Speed += 5.0f;

	OnRep_Speed();
}

void UStatManagementComponent::IncreasePower()
{
	Power += 5.0f;

	OnRep_Power();
}

void UStatManagementComponent::RecurberyMp()
{
	CurMp = CurMp + 10.0f;
	CurMp = FMath::Clamp(CurMp, 0.0f, MaxMp);

	UE_LOG(LogTemp, Warning, TEXT("%f"), CurMp);

	OnRep_CurMp();
}

void UStatManagementComponent::BurfPower()
{
	Power = Power + 10.0f;

	UE_LOG(LogTemp, Warning, TEXT("%f"), Power);

	OnRep_Power();

	GetWorld()->GetTimerManager().SetTimer(Th_PowerHandle, [&]()
		{
			GetBackPowerVal();
			UE_LOG(LogTemp, Warning, TEXT("%f"), Power);
		}, 10, false);
}

void UStatManagementComponent::BurfSpeed()
{
	Speed = Speed + 10.0f;

	UE_LOG(LogTemp, Warning, TEXT("%f"), Speed);

	OnRep_Speed();

	GetWorld()->GetTimerManager().SetTimer(Th_SpeedHandle, [&]()
		{
			GetBackSpeedVal();
			UE_LOG(LogTemp, Warning, TEXT("%f"), Speed);
		}, 10, false);
}

void UStatManagementComponent::GetBackPowerVal()
{
	Power = Power - 10.0f;

	UE_LOG(LogTemp, Warning, TEXT("%f"), Power);

	OnRep_Power();
}

void UStatManagementComponent::GetBackSpeedVal()
{
	Speed = Speed - 10.0f;

	UE_LOG(LogTemp, Warning, TEXT("%f"), Speed);

	OnRep_Speed();
}
