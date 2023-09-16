// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatManagementComponent.generated.h"

enum class EItemType : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDele_UpdateHp_TwoParams, float, CurHp, float, MaxHp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDele_UpdateMp_TwoParams, float, CurMp, float, MaxMp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDele_UpdateSpeed_TwoParams, float, CurSpeed, float, MaxSpeed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDele_UpdatePower_TwoParams, float, CurPower, float, MaxPower);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ITEMPLUGIN_API UStatManagementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatManagementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UFUNCTION()
	void OnRep_CurHp();

	UFUNCTION()
	void OnRep_MaxHp();

	UFUNCTION()
	void OnRep_CurMp();

	UFUNCTION()
	void OnRep_MaxMp();

	UFUNCTION()
	void OnRep_CurSpeed();

	UFUNCTION()
	void OnRep_MaxSpeed();

	UFUNCTION()
	void OnRep_CurPower();

	UFUNCTION()
	void OnRep_MaxPower();
public:
	UPROPERTY(ReplicatedUsing = OnRep_CurHp)
	float CurHp = 0.0f;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHp)
	float MaxHp = 100.0f;

	UPROPERTY(ReplicatedUsing = OnRep_CurHp)
	float CurMp = 0.0f;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHp)
	float MaxMp = 100.0f;

	UPROPERTY(ReplicatedUsing = OnRep_CurHp)
	float CurSpeed = 0.0f;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHp)
	float MaxSpeed = 100.0f;

	UPROPERTY(ReplicatedUsing = OnRep_CurHp)
	float CurPower = 0.0f;

	UPROPERTY(ReplicatedUsing = OnRep_MaxHp)
	float MaxPower = 100.0f;
		
public:
	/*UFUNCTION(BlueprintCallable)
	void ComparisonItemType(EItemType eItemType);*/

	UFUNCTION(BlueprintCallable)
	void IncreaseMaxHp();

	UFUNCTION(BlueprintCallable)
	void RecurberyHp();

	UFUNCTION(BlueprintCallable)
	void IncreaseMaxMp();

	UFUNCTION(BlueprintCallable)
	void IncreaseSpeed();

	UFUNCTION(BlueprintCallable)
	void IncreasePower();

	UFUNCTION(BlueprintCallable)
	void RecurberyMp();

	UFUNCTION(BlueprintCallable)
	void BurfPower();

	UFUNCTION(BlueprintCallable)
	void BurfSpeed();


public:
	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateHp_TwoParams Fuc_Dele_UpdateHp;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateMp_TwoParams Fuc_Dele_UpdateMp;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdateSpeed_TwoParams Fuc_Dele_UpdateSpeed;

	UPROPERTY(BlueprintAssignable, VisibleAnywhere, BlueprintCallable)
	FDele_UpdatePower_TwoParams Fuc_Dele_UpdatePower;
};
