// Fill out your copyright notice in the Description page of Project Settings.


#include "StatManagementComponent.h"
#include "Net/UnrealNetwork.h"

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
	DOREPLIFETIME(UStatManagementComponent, CurSpeed);
	DOREPLIFETIME(UStatManagementComponent, MaxSpeed);
	DOREPLIFETIME(UStatManagementComponent, CurPower);
	DOREPLIFETIME(UStatManagementComponent, MaxPower);
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

void UStatManagementComponent::OnRep_CurSpeed()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_CurSpeed"));
	if (Fuc_Dele_UpdateSpeed.IsBound())
		Fuc_Dele_UpdateSpeed.Broadcast(CurSpeed, MaxSpeed);
}

void UStatManagementComponent::OnRep_MaxSpeed()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_MaxSpeed"));
	if (Fuc_Dele_UpdateSpeed.IsBound())
		Fuc_Dele_UpdateSpeed.Broadcast(CurSpeed, MaxSpeed);
}

void UStatManagementComponent::OnRep_CurPower()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_CurPower"));
	if (Fuc_Dele_UpdatePower.IsBound())
		Fuc_Dele_UpdatePower.Broadcast(CurPower, MaxPower);
}

void UStatManagementComponent::OnRep_MaxPower()
{
	UE_LOG(LogTemp, Warning, TEXT("OnRep_MaxPower"));
	if (Fuc_Dele_UpdatePower.IsBound())
		Fuc_Dele_UpdatePower.Broadcast(CurPower, MaxPower);
}

void UStatManagementComponent::IncreaseMaxHp()
{
	MaxHp += 30;

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
	MaxMp += 30;

	OnRep_MaxMp();
}

void UStatManagementComponent::IncreaseSpeed()
{
	MaxSpeed += 30;

	OnRep_MaxSpeed();
}

void UStatManagementComponent::IncreasePower()
{
	MaxPower += 30;

	OnRep_MaxPower();
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
	CurPower = CurPower + 10.0f;
	CurPower = FMath::Clamp(CurPower, 0.0f, MaxPower);

	UE_LOG(LogTemp, Warning, TEXT("%f"), CurPower);

	OnRep_CurPower();
}

void UStatManagementComponent::BurfSpeed()
{
	CurSpeed = CurSpeed + 10.0f;
	CurSpeed = FMath::Clamp(CurSpeed, 0.0f, MaxSpeed);

	UE_LOG(LogTemp, Warning, TEXT("%f"), CurSpeed);

	OnRep_CurSpeed();
}

